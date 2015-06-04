
// MainActivity.c
#include "MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_example_hellojni_MainActivity_getHelloJNI
  (JNIEnv *pEnv, jclass clazz)
{
	return (*pEnv)->NewStringUTF(pEnv, "Hello, JNI");
}

