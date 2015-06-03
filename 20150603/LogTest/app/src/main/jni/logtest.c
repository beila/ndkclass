#include <android/log.h>
#include "com_example_logtest_MainActivity.h"

#define LOG_TAG ("NATIVE_LOG")
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_com_example_logtest_MainActivity_logClick
  (JNIEnv *pEnv, jobject thiz, jobject view) {
    LOGI("view is clicked");
  }
