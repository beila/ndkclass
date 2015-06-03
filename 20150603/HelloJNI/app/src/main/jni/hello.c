#include "com_example_hellojni_MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_example_hellojni_MainActivity_getHelloJni
  (JNIEnv *pEnv, jobject thiz)
{
    return (*pEnv)->NewStringUTF(pEnv, "hello, jni");
}
