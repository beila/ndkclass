
// Hello.c
#include <jni.h>

jstring Java_com_example_Hello_getHelloWorld(JNIEnv *pEnv, jobject thiz)
{
	// jstring (*NewStringUTF)(JNIEnv*, const char*);
	return (*pEnv)->NewStringUTF(pEnv, "hello, world");
}

