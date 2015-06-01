#include <stdio.h>
#include <jni.h>

void Java_com_example_Hello_printHelloJni(JNIEnv *pEnv, jclass clazz) {
    printf("hello, jni from c\n");
}
