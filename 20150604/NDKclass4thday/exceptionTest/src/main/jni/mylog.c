#include <stdio.h>
#include "com_lge_ndkclass4thday_MainActivity.h"

#include <android/log.h>
#define LOG_TAG ("mylog")
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

void throwNonExistentStringException(JNIEnv *pEnv) {
    jclass exceptionClass = (*pEnv)->FindClass(pEnv, "com/lge/ndkclass4thday/NonExistentStringException");
    if (exceptionClass == NULL) {
        LOGE("NonExistentStringException class not found");
        return;
    }

    (*pEnv)->ThrowNew(pEnv, exceptionClass, "No string");
}

JNIEXPORT void JNICALL Java_com_lge_ndkclass4thday_MainActivity_printLog
    (JNIEnv *pEnv, jclass clazz, jstring log) {
        int len = (*pEnv)->GetStringLength(pEnv, log);
        if (len == 0) {
            throwNonExistentStringException(pEnv);
            return;
        }

        const char *pStr = (*pEnv)->GetStringChars(pEnv, log, 0);
        LOGI("%s", pStr);

        (*pEnv)->ReleaseStringUTFChars(pEnv, log, pStr);
    }
