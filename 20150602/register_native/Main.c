#include <stdio.h>
#include <jni.h>

void printHelloWorld(JNIEnv *pEnv, jclass clazz) {
    printf("hello world!\n");
}

jstring getHelloWorld(JNIEnv *pEnv, jclass clazz) {
    return (*pEnv)->NewStringUTF(pEnv, "hello, world");
}

jint JNI_OnLoad(JavaVM *vm, void* reserved) {
    JNIEnv* pEnv;
    if ((*vm)->GetEnv(vm, (void**)&pEnv, JNI_VERSION_1_6) != JNI_OK) {
	fprintf(stderr, "GetEnv Error\n");
	return JNI_ERR;
    }

    JNINativeMethod mTable[2];
    mTable[0].name = "printHelloWorld";
    mTable[0].signature = "()V";
    mTable[0].fnPtr = printHelloWorld;
    mTable[1].name = "getHelloWorld";
    mTable[1].signature = "()Ljava/lang/String;";
    mTable[1].fnPtr = getHelloWorld;

    jclass mainClass = (*pEnv)->FindClass(pEnv, "com/example/Main");

    (*pEnv)->RegisterNatives(pEnv, mainClass, mTable, 2);

    return JNI_VERSION_1_6;
}
