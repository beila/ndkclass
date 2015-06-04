
// MainActivity.c
#include <stdio.h>	// NULL

#define LOG_TAG     ("com.example.jnitoast")
#include <android/log.h>   
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "MainActivity.h"

// Toast.makeText(this, "KKK", Toast.LENGTH_SHORT).show();

JNIEXPORT void JNICALL Java_com_example_jnitoast_MainActivity_displayToastShort
  (JNIEnv *pEnv, jobject thiz, jobject charSeq)
{
	// 1. find Toast class
	jclass toastClass = (*pEnv)->FindClass(pEnv, "android/widget/Toast");
	if(toastClass == NULL)
	{
		LOGE("FindClass Error(%d)", __LINE__);
		return;
	}

	// 2. find makeText method
	jmethodID makeText = (*pEnv)->GetStaticMethodID(
			pEnv, toastClass, "makeText", 
			"(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
	if(makeText == NULL)
	{
		LOGE("GetStaticMethodID Error(%d)", __LINE__);
		return;
	}

	// 3. call static method
	jobject toastObject = (*pEnv)->CallStaticObjectMethod(pEnv, toastClass,
			makeText, thiz, charSeq, 0);
	if(toastObject == NULL)
	{
		LOGE("CallStaticObjectMethod Error(%d)", __LINE__);
		return;
	}


	// 4. find show method 
	jmethodID show = (*pEnv)->GetMethodID(pEnv, toastClass, "show", "()V");
	if(show == NULL)
	{
		LOGE("GetMethodID Error(%d)", __LINE__);
		return;
	}

	// 5. call show
	(*pEnv)->CallVoidMethod(pEnv, toastObject, show);
}

JNIEXPORT void JNICALL Java_com_example_jnitoast_MainActivity_displayToastLong
  (JNIEnv *pEnv, jobject thiz, jobject charSeq)
{
	// 1. find Toast class
	jclass toastClass = (*pEnv)->FindClass(pEnv, "android/widget/Toast");
	if(toastClass == NULL)
	{
		LOGE("FindClass Error(%d)", __LINE__);
		return;
	}

	// 2. find makeText method
	jmethodID makeText = (*pEnv)->GetStaticMethodID(
			pEnv, toastClass, "makeText", 
			"(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
	if(makeText == NULL)
	{
		LOGE("GetStaticMethodID Error(%d)", __LINE__);
		return;
	}

	// 3. call static method
	jobject toastObject = (*pEnv)->CallStaticObjectMethod(pEnv, toastClass,
			makeText, thiz, charSeq, 1);
	if(toastObject == NULL)
	{
		LOGE("CallStaticObjectMethod Error(%d)", __LINE__);
		return;
	}


	// 4. find show method 
	jmethodID show = (*pEnv)->GetMethodID(pEnv, toastClass, "show", "()V");
	if(show == NULL)
	{
		LOGE("GetMethodID Error(%d)", __LINE__);
		return;
	}

	// 5. call show
	(*pEnv)->CallVoidMethod(pEnv, toastObject, show);
}

