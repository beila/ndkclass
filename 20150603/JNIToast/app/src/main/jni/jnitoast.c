#include "com_example_jnitoast_LoginActivity.h"

#include <android/log.h>

#define NULL 0
#define LOG_TAG "JNI_TOAST"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_com_example_jnitoast_LoginActivity_nativeToast
  (JNIEnv *pEnv, jobject thiz, jstring msg, jint length) {
    jclass toastClass = (*pEnv)->FindClass(pEnv, "android/widget/Toast");
    if (toastClass == NULL) {
      LOGE("FindClass Error(%d)", __LINE__);
      return;
    }

    jmethodID makeTextMethod = (*pEnv)->GetStaticMethodID(pEnv, toastClass, "makeText", "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
    if (toastClass == NULL) {
      LOGE("GetStaticMethodID(.. makeText ..) Error(%d)", __LINE__);
      return;
    }

    jobject toast = (*pEnv)->CallStaticObjectMethod(pEnv, toastClass, makeTextMethod, thiz, msg, length);
    if (toast == NULL) {
      LOGE("CallStaticObjectMethod(.. makeText ..) Error(%d)", __LINE__);
      return;
    }

    jmethodID showMethod = (*pEnv)->GetMethodID(pEnv, toastClass, "show", "()V");
    if (toastClass == NULL) {
      LOGE("GetMethodID(.. show ..) Error(%d)", __LINE__);
      return;
    }

    (*pEnv)->CallVoidMethod(pEnv, toast, showMethod);
    if (toast == NULL) {
      LOGE("CallVoidMethod(.. show ..) Error(%d)", __LINE__);
      return;
    }
  }
