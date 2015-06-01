
// Hello.c
#include <stdio.h>

#include "Hello.h"

JNIEXPORT void JNICALL Java_com_example_lge_Hello_printHello
  (JNIEnv *pEnv, jclass clazz)
{
	printf("hello\n");
}

JNIEXPORT void JNICALL Java_com_example_lge_Hello_printWorld
  (JNIEnv *pEnv, jobject thiz)
{
	printf("world\n");
}

