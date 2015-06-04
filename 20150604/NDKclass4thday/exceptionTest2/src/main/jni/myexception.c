#include "com_lge_ndkexceptiontest2_MainActivity.h"

#include <android/log.h>

#define NULL 0
#define LOG_TAG ("myexception")
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_com_lge_ndkexceptiontest2_MainActivity_doMakeException
  (JNIEnv *env, jobject activity) {
    jclass activityClass = (*env)->FindClass(env, "com/lge/ndkexceptiontest2/MainActivity");
    if (activityClass == NULL) {
        LOGE("class not found");
        return;
    }

    jmethodID makeExceptionID = (*env)->GetMethodID(env, activityClass, "makeException", "()V");
    if (makeExceptionID == NULL) {
        LOGE("method not found");
        return;
    }

    (*env)->CallVoidMethod(env, activity, makeExceptionID);

    jthrowable exception = (*env)->ExceptionOccurred(env);
    if (exception) {
        (*env)->ExceptionDescribe(env);
        (*env)->ExceptionClear(env);
    }
  }
