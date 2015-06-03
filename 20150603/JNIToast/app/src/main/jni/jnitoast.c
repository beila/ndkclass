#include "com_example_jnitoast_LoginActivity.h"

JNIEXPORT void JNICALL Java_com_example_jnitoast_LoginActivity_nativeToast
  (JNIEnv *pEnv, jobject thiz, jstring msg, jint length) {
    jclass toastClass = (*pEnv)->FindClass(pEnv, "android/widget/Toast");

    jmethodID makeTextMethod = (*pEnv)->GetStaticMethodID(pEnv, toastClass, "makeText", "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
    jobject toast = (*pEnv)->CallStaticObjectMethod(pEnv, toastClass, makeTextMethod, thiz, msg, length);

    jmethodID showMethod = (*pEnv)->GetMethodID(pEnv, toastClass, "show", "()V");
    (*pEnv)->CallVoidMethod(pEnv, toast, showMethod);
  }
