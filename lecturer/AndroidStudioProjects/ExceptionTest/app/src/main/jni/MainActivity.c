
#define LOG_TAG			"ExceptionTest"

// MainActivity.c
#include <stdio.h>	// for NULL

#include <jni.h>
#include <android/log.h>	// ldLibs "log"
#define LOGI(...)	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)	__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "MainActivity.h"

// 예외를 던지는 함수를 설계합니다.
void throwNotExistStringException(JNIEnv *pEnv)
{
	jclass notExistStringExceptionClass
		= (*pEnv)->FindClass(pEnv, "com/example/exceptiontest/NotExistStringException");
	if (notExistStringExceptionClass == NULL)
	{
		LOGE("FindClass Error");
		return;
	}

	// jint (*ThrowNew)(JNIEnv *, jclass, const char *);
	(*pEnv)->ThrowNew(pEnv, notExistStringExceptionClass, "not exist string");
}

JNIEXPORT void JNICALL Java_com_example_exceptiontest_MainActivity_printLog
	(JNIEnv *pEnv, jclass clazz, jstring msg)
{
	// 문자열의 길이를 검사
	// jsize (*GetStringLength)(JNIEnv*, jstring);
	int len = (*pEnv)->GetStringLength(pEnv, msg);
	if (len == 0)	// NULL String
	{
		throwNotExistStringException(pEnv);
		return;
	}

	// const jchar* (*GetStringChars)(JNIEnv*, jstring, jboolean*);
	const char *pStr = (*pEnv)->GetStringChars(pEnv, msg, 0);
	LOGI("%s", pStr);

	//void (*ReleaseStringUTFChars)(JNIEnv*, jstring, const char*);
	(*pEnv)->ReleaseStringUTFChars(pEnv, msg, pStr);
}


