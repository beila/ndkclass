
// Main.c
#include <stdio.h>	// for printf

#include <jni.h>

void Java_com_example_lge_Main_printHelloWorld(JNIEnv* pEnv, jclass clazz)
{
	printf("hello, world\n");
}
