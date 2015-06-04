
#define LOG_TAG     ("com.example.exceptiontest2")

// MainAcitvity.c
#include <stdio.h>

#include <jni.h>
#include <android/log.h>  
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "MainActivity.h"

JNIEXPORT void JNICALL Java_com_example_exceptiontest2_MainActivity_doMakeExeption
  (JNIEnv *pEnv, jobject thiz)
{
	// makeException 메서드 호출

	// 1. MainActivity.java 클래스 파일 찾기
	jclass mainActivityClass =
		(*pEnv)->FindClass(pEnv, "com/example/exceptiontest2/MainActivity");
	if (mainActivityClass == NULL)
	{
		LOGE("FindClass Error");
		return;
	}

	// 2. makeException 메서드 아이디 찾기
	jmethodID makeException = (*pEnv)->GetMethodID(pEnv, mainActivityClass,
			"makeException", "()V");
	if (makeException == NULL)
	{
		LOGE("GetMethodID Error");
		return;
	}

	// 3. 메서드 호출
	// void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...); 
	(*pEnv)->CallVoidMethod(pEnv, thiz, makeException);

	// 4. 예외 발생 검사
	// jthrowable  (*ExceptionOccurred)(JNIEnv*);
	jthrowable exception = (*pEnv)->ExceptionOccurred(pEnv);
	if (exception) {
		//  void        (*ExceptionDescribe)(JNIEnv*); 
		(*pEnv)->ExceptionDescribe(pEnv);	// printStackTrace();

		// void        (*ExceptionClear)(JNIEnv*); 
		(*pEnv)->ExceptionClear(pEnv);
	}
}

