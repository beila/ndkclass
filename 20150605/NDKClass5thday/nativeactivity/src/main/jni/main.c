#include <android/log.h>
#define LOG_TAG ("NATIVE_ACTIVITY")
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "android_native_app_glue.h"

void onAppCmd(struct android_app* app, int32_t cmd) {
	switch(cmd) {
		case APP_CMD_INPUT_CHANGED: LOGI("APP_CMD_INPUT_CHANGED"); break;
		case APP_CMD_INIT_WINDOW: LOGI("APP_CMD_INIT_WINDOW"); break;
		case APP_CMD_TERM_WINDOW: LOGI("APP_CMD_TERM_WINDOW"); break;
		case APP_CMD_WINDOW_RESIZED: LOGI("APP_CMD_WINDOW_RESIZED"); break;
		case APP_CMD_WINDOW_REDRAW_NEEDED: LOGI("APP_CMD_WINDOW_REDRAW_NEEDED"); break;
		case APP_CMD_CONTENT_RECT_CHANGED: LOGI("APP_CMD_CONTENT_RECT_CHANGED"); break;
		case APP_CMD_GAINED_FOCUS: LOGI("APP_CMD_GAINED_FOCUS"); break;
		case APP_CMD_LOST_FOCUS: LOGI("APP_CMD_LOST_FOCUS"); break;
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

int32_t onInputEventTypeMotion(struct android_app* app, AInputEvent* event) {
	int count = AMotionEvent_getPointerCount(event);
	int i;
	for (i = 0; i < count; ++i) {
		int x = AMotionEvent_getX(event, i);
		int y = AMotionEvent_getY(event, i);
		LOGI("(%d) x=%4d, y=%4d", i, x, y);
	}
	return 0;
}

int32_t onInputEvent(struct android_app* app, AInputEvent* event) {
	switch(AInputEvent_getType(event)) {
		case AINPUT_EVENT_TYPE_KEY: LOGI("AINPUT_EVENT_TYPE_KEY"); break;
		case AINPUT_EVENT_TYPE_MOTION: LOGI("AINPUT_EVENT_TYPE_MOTION");
									   return onInputEventTypeMotion(app, event);
	}

	return 0;
}

void android_main(struct android_app* app) {
    // Make sure glue isn't stripped.
    app_dummy();

	app->onAppCmd = onAppCmd;
	app->onInputEvent = onInputEvent;

	while(1) {
		int ident;
		int events;
		struct android_poll_source *source;

		while((ident = ALooper_pollAll(-1, NULL, &events, (void**)&source)) >= 0) {
			if (source != NULL) {
				LOGV("poll with source");
				source->process(app, source);
			}

			if (app->destroyRequested != 0) {
				return;
			}
		}
	}
}

