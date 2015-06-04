
// MainActivity.c
#define LOG_TAG		("com.example.logtest")
#include <android/log.h>	// __android_log_print, ...

#define LOGI(...)	\
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#include "MainActivity.h"

JNIEXPORT void JNICALL Java_com_example_logtest_MainActivity_printLog
  (JNIEnv *pEnv, jclass clazz)
{
	LOGI("clicked LogTest' Button!");
}

