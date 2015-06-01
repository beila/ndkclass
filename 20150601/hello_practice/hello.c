#include <stdio.h>
#include <jni.h>

void Java_com_example_lge_Main_printHelloWorld(JNIEnv *pEnv, jclass clazz) {
    printf("Hello world!\n");
}
