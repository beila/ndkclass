
#define LOG_TAG     ("ThreadTest")
// MainActivity.c
#include <pthread.h>

#include <android/log.h>
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "MainActivity.h"

jclass gMainActivityClass = 0;
jmethodID callback;
JavaVM *gVM;

int running = 0;		// thread flag
pthread_t tid;

void notify( int cnt )
{
	JNIEnv *pEnv = 0;

	if( gVM == 0 )
	{
		LOGE( "gVM is NULL" );
		return;
	}

	(*gVM)->AttachCurrentThread( gVM, &pEnv, NULL );
	if( pEnv == 0 || gMainActivityClass == 0 )
	{
		LOGE( "pEnv or gMainActivityClass is NULL" );
		(*gVM)->DetachCurrentThread(gVM);
		running = 0;
		return;
	}

	(*pEnv)->CallStaticVoidMethod( pEnv, gMainActivityClass, callback, cnt );
	(*gVM)->DetachCurrentThread(gVM);
}



void* t_function( void* p )
{
	int cnt = 0;
	while( running )
	{
		notify( cnt++ );
		sleep(1);
	}

	return 0;
}


JNIEXPORT jint JNICALL Java_com_example_threadtest_MainActivity_startThread
(JNIEnv *pEnv, jobject thiz)
{
	jclass mainActivityClass = (*pEnv)->FindClass(
			pEnv, "com/example/threadtest/MainActivity");
	if(mainActivityClass == NULL)
	{
		LOGE("FindClass");
		return -1;
	}

	if(gMainActivityClass == 0)
		gMainActivityClass = (*pEnv)->NewGlobalRef(pEnv, mainActivityClass);

	callback = (*pEnv)->GetStaticMethodID(pEnv, gMainActivityClass, "callback",
			"(I)V");
	if(callback == 0)
	{
		LOGE("GetStaticMethodID");
		(*pEnv)->DeleteGlobalRef(pEnv, gMainActivityClass);
		return -1;
	}

	running = 1;
	tid = pthread_create( &tid, NULL, t_function, NULL );
	if( tid < 0 )
	{
		LOGE( "pthread_create error" );
		(*pEnv)->DeleteGlobalRef( pEnv, gMainActivityClass );
		return -1;
	}

	(*pEnv)->GetJavaVM( pEnv, &gVM );
	return 0;
}

	JNIEXPORT jint JNICALL Java_com_example_threadtest_MainActivity_stopThread
(JNIEnv *pEnv, jobject thiz)
{
	running = 0;
}
