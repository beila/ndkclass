#include "com_example_threadtest_MainActivity.h"

#include <android/log.h>
#define LOG_TAG ("NATIVE_THREAD")
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include <pthread.h>

jclass gMainActivityClass = 0;
jmethodID callback;
int running = 0;
pthread_t tid;
JavaVM *gVM;

void notify(int count) {
	JNIEnv *env = 0;
	if (gVM == 0) {
		LOGE("gVM is NULL");
		return;
	}

	(*gVM)->AttachCurrentThread(gVM, &env, NULL);
	if (env == 0 || gMainActivityClass == 0) {
		LOGE("env or gMainActivityClass is NULL");
		(*gVM)->DetachCurrentThread(gVM);
		running = 0;
		return;
	}

	(*env)->CallStaticVoidMethod(env, gMainActivityClass, callback, count);
	(*gVM)->DetachCurrentThread(gVM);
}

void* t_function(void* p) {
	int cnt = 0;
	while (running) {
		sleep(1);
		notify (cnt++);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_example_threadtest_MainActivity_startThread
  (JNIEnv *env, jobject thiz) {
    jclass mainActivityClass = (*env)->FindClass(env, "com/example/threadtest/MainActivity");
	if (mainActivityClass == NULL) {
		LOGE("FindClass");
		return -1;
	}

	if (gMainActivityClass == 0) {
		gMainActivityClass = (*env)->NewGlobalRef(env, mainActivityClass);
	}

	callback = (*env)->GetStaticMethodID(env, gMainActivityClass, "callback", "(I)V");
	if (callback == 0) {
		LOGE("GetStaticMethodID");
		(*env)->DeleteGlobalRef(env, gMainActivityClass);
		return -1;
	}

	pthread_create(&tid, NULL, t_function, NULL);
	if (tid < 0) {
		LOGE("pthread_create");
		(*env)->DeleteGlobalRef(env, gMainActivityClass);
		return -1;
	}

	running = 1;

	(*env)->GetJavaVM(env, &gVM);
	return 0;
  }

JNIEXPORT jint JNICALL Java_com_example_threadtest_MainActivity_stopThread
  (JNIEnv *env, jobject thiz) {
	  running = 0;
  }
