
#if 0
#define LOG_TAG			("NativeApp")

// main.c for NativeActivity
#include <jni.h>
#include <errno.h>
#include "android_native_app_glue.h"	// #include <android_native_app_glue.h>

#include <android/log.h>
#define LOGI(...)	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)	__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// custom context
struct Engine {
	int32_t x, y;
	int animating;	
	ANativeWindow_Buffer mBuffer;
	struct android_app *context;
};

void init_display(struct Engine* engine)
{
	ANativeWindow *window = engine->context->window;
	ANativeWindow_setBuffersGeometry(window, 0, 0, WINDOW_FORMAT_RGBX_8888);
}

void term_display(struct Engine* engine)
{
	engine->animating = 0;
}

void onAppCmd(struct android_app* app, int32_t cmd)
{
	struct Engine *engine = (struct Engine*)app->userData;
	switch(cmd)
	{
		case APP_CMD_INPUT_CHANGED: LOGI("APP_CMD_INPUT_CHANGED"); break;
		case APP_CMD_INIT_WINDOW:
									LOGI("APP_CMD_INIT_WINDOW");
									init_display(engine);
									break;
		case APP_CMD_TERM_WINDOW:
									LOGI("APP_CMD_TERM_WINDOW");
									term_display(engine);	
									break;

		case APP_CMD_WINDOW_RESIZED: LOGI("APP_CMD_WINDOW_RESIZED"); break;
		case APP_CMD_WINDOW_REDRAW_NEEDED: LOGI("APP_CMD_WINDOW_REDRAW_NEEDED"); break;
		case APP_CMD_CONTENT_RECT_CHANGED: LOGI("APP_CMD_CONTENT_RECT_CHANGED"); break;
		case APP_CMD_GAINED_FOCUS: LOGI("APP_CMD_GAINED_FOCUS"); break;
		case APP_CMD_LOST_FOCUS:
								   LOGI("APP_CMD_LOST_FOCUS");
								   engine->animating = 0;
								   drawing(engine);
								   break;
		case APP_CMD_CONFIG_CHANGED: LOGI("APP_CMD_CONFIG_CHANGED"); break;
		case APP_CMD_LOW_MEMORY: LOGI("APP_CMD_LOW_MEMORY"); break;
		case APP_CMD_START: LOGI("APP_CMD_START"); break;
		case APP_CMD_RESUME: LOGI("APP_CMD_RESUME"); break;
		case APP_CMD_SAVE_STATE: LOGI("APP_CMD_SAVE_STATE"); break;
		case APP_CMD_PAUSE: LOGI("APP_CMD_PAUSE"); break;
		case APP_CMD_STOP: LOGI("APP_CMD_STOP"); break;
		case APP_CMD_DESTROY: LOGI("APP_CMD_DESTROY"); break;
	}
}

int32_t onInputEvent(struct android_app* app, AInputEvent* event)
{
	struct Engine *engine = (struct Engine*)app->userData;

	// 화면 상의 터치 이벤트
	if(AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION)
	{
		int x = AMotionEvent_getX(event, 0);
		int y = AMotionEvent_getY(event, 0);
		LOGI("x=%4d, y=%4d", x, y);

		engine->x = x;
		engine->y = y;
		engine->animating = 1;

		return 1;
	}
	return 0;
}

void drawing(struct Engine *engine)
{
	ANativeWindow *window = engine->context->window;

	ANativeWindow_lock(window, &engine->mBuffer, 0);
	//---------------------------------------------

	int x, y;
	const int halfSize = 64 / 2;

	const upLeftX = engine->x - halfSize;
	const upLeftY = engine->y - halfSize;
	const downRightX = engine->x + halfSize;
	const downRightY = engine->y + halfSize;

	//	memset(engine->mBuffer.bits, 0, engine->mBuffer.stride *
	//			engine->mBuffer.height * sizeof(uint32_t*));

	uint32_t *line = ((uint32_t*)engine->mBuffer.bits) +
		(engine->mBuffer.stride * upLeftY);
	for(y = upLeftY; y <= downRightY; y++)
	{
		for(x = upLeftX; x <= downRightX; x++)
			line[x] = 255;
		line = line + engine->mBuffer.stride;
	}
	//-----------------------------------------------------
	ANativeWindow_unlockAndPost(window);
}


void android_main(struct android_app *app) {

	app_dummy();	// Make sure glue isn't stripped.

	struct Engine engine = { 0, };
	app->userData = &engine;
	app->onAppCmd = onAppCmd;
	app->onInputEvent = onInputEvent;
	engine.context = app;

	while(1)
	{
		int ident;
		int events;
		struct android_poll_source *source;

		// -1 이벤트가 들어올 때까지 블록(block)
		while((ident = ALooper_pollAll(engine.animating ? 0 : -1, NULL, &events, (void**)&source)) >= 0) {
			if(source != NULL)	// 메세지 큐에 이벤트가 들어온 것을 의미
			{
				source->process(app, source);
			}

			// 네이티브 애플리케이션이 종료될 경우
			if(app->destroyRequested != 0) {
				// 종료 처리
				return;
			}
		}

		if(engine.animating)
			drawing(&engine);
	}	// end of while(1)
}
#endif

#define LOG_TAG			("NativeApp")

// main.c for NativeActivity
#include <jni.h>
#include <errno.h>
#include "android_native_app_glue.h"	// #include <android_native_app_glue.h>

#include <android/sensor.h>
#include <android/log.h>
#define LOGI(...)	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)	__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// custom context
struct Engine {
	struct android_app *context;
	ASensorManager* sensorManager;          // 센서 매니저
	const ASensor* accelerometerSensor;     // 중력 센서
	const ASensor* magneticSensor;          // 지자기 센서
	const ASensor* gyroscopeSensor;         // 자이로스코프 센서
	const ASensor* lightSensor;             // 조도 센서
	ASensorEventQueue* sensorEventQueue;    // 센서 수신을 위한 큐
};


void onAppCmd(struct android_app* app, int32_t cmd)
{
	struct Engine *engine = (struct Engine *)app->userData;
	switch(cmd)
	{
		case APP_CMD_GAINED_FOCUS:
			if (engine->accelerometerSensor != NULL) {
				ASensorEventQueue_enableSensor(engine->sensorEventQueue, engine->accelerometerSensor);
				ASensorEventQueue_setEventRate(engine->sensorEventQueue, engine->accelerometerSensor, (1000L / 60) * 1000);
			}

			if (engine->magneticSensor != NULL) {
				ASensorEventQueue_enableSensor(engine->sensorEventQueue, engine->magneticSensor);
				ASensorEventQueue_setEventRate(engine->sensorEventQueue, engine->magneticSensor, (1000L / 60) * 1000);
			}

			if (engine->gyroscopeSensor != NULL) {
				ASensorEventQueue_enableSensor(engine->sensorEventQueue, engine->gyroscopeSensor);
				ASensorEventQueue_setEventRate(engine->sensorEventQueue, engine->gyroscopeSensor, (1000L / 60) * 1000);
			}

			if (engine->lightSensor != NULL) {
				ASensorEventQueue_enableSensor(engine->sensorEventQueue, engine->lightSensor);
				ASensorEventQueue_setEventRate(engine->sensorEventQueue, engine->lightSensor, (1000L / 60) * 1000);
			}

			break;

		case APP_CMD_LOST_FOCUS:
			if (engine->accelerometerSensor != NULL)
				ASensorEventQueue_disableSensor(engine->sensorEventQueue, engine->accelerometerSensor);

			if (engine->magneticSensor != NULL)
				ASensorEventQueue_disableSensor(engine->sensorEventQueue, engine->magneticSensor);

			if (engine->gyroscopeSensor != NULL)
				ASensorEventQueue_disableSensor(engine->sensorEventQueue, engine->gyroscopeSensor);

			if (engine->lightSensor != NULL)
				ASensorEventQueue_disableSensor(engine->sensorEventQueue, engine->lightSensor);

			break;
	}
}

void android_main(struct android_app *app) {

	app_dummy();	// Make sure glue isn't stripped.

	struct Engine engine = { 0, };
	app->userData = &engine;
	app->onAppCmd = onAppCmd;

	// 1. 센서 매니저 획득
	engine.sensorManager = ASensorManager_getInstance();

	// 각 센서의 포인터 획득
	engine.accelerometerSensor = ASensorManager_getDefaultSensor(engine.sensorManager, ASENSOR_TYPE_ACCELEROMETER);
	if( engine.accelerometerSensor == NULL ) LOGI( "no accelerometerSensor" );

	engine.magneticSensor = ASensorManager_getDefaultSensor(engine.sensorManager,
			ASENSOR_TYPE_MAGNETIC_FIELD);
	if( engine.magneticSensor == NULL ) LOGI( "no magneticSensor" );

	engine.gyroscopeSensor = ASensorManager_getDefaultSensor(engine.sensorManager,
			ASENSOR_TYPE_GYROSCOPE);
	if( engine.gyroscopeSensor == NULL ) LOGI( "no gyroscopeSensor" );

	engine.lightSensor = ASensorManager_getDefaultSensor(engine.sensorManager,
			ASENSOR_TYPE_LIGHT);
	if( engine.lightSensor == NULL ) LOGI( "no lightSensor" );

	// 수신된 센서 데이터 저장을 위한 큐 설정
	engine.sensorEventQueue = ASensorManager_createEventQueue(engine.sensorManager,
			app->looper, LOOPER_ID_USER, NULL, NULL);


	while(1)
	{
		int ident;
		int events;
		struct android_poll_source *source;

		while((ident = ALooper_pollAll(-1, NULL, &events, (void**)&source)) >= 0)
		{
			if(source != NULL)	{ source->process(app, source); } 

			if(ident == LOOPER_ID_USER)	// 센서로부터 온 이벤트인 경우
			{
				if( engine.accelerometerSensor != NULL && engine.gyroscopeSensor != NULL && engine.magneticSensor != NULL && engine.lightSensor != NULL )
				{
					ASensorEvent event[4];
					int count, i;
					while( (count = ASensorEventQueue_getEvents(engine.sensorEventQueue, event, 4)) > 0 )
					{
						for( i = 0; i < count; i++ )
						{
							switch(event[i].type)
							{
								case ASENSOR_TYPE_ACCELEROMETER:
									LOGI("accelerometer: x=%f y=%f z=%f",
											event[i].acceleration.x,
											event[i].acceleration.y,
											event[i].acceleration.z);
									break;
								case ASENSOR_TYPE_GYROSCOPE:
									LOGI("GYROSCOPE: azimuth=%f pitch=%f roll=%f",
											event[i].vector.azimuth,
											event[i].vector.pitch,
											event[i].vector.roll);
									break;
								case ASENSOR_TYPE_MAGNETIC_FIELD:
									LOGI("MAGNETIC: v[0]=%f v[1]=%f v[2]=%f",
											event[i].magnetic.v[0],
											event[i].magnetic.v[1],
											event[i].magnetic.v[2]);
									break;
								case ASENSOR_TYPE_LIGHT:
									LOGI("LIGHT: light=%f", event[i].light);
									break;
							}       
						}   
					}   
				}   
			}   

			if(app->destroyRequested != 0) {
				return;
			}
		}
	}	// end of while(1)
}
