#include <jni.h>
JNIEXPORT jobject JNICALL Java_Main_newMath(JNIEnv *pEnv, jclass clazz) {
    jclass mathClass = (*pEnv)->FindClass(pEnv, "Math");

    jmethodID ctor = (*pEnv)->GetMethodID(pEnv, mathClass, "<init>", "()V");

    jobject mathObject = (*pEnv)->NewObject(pEnv, ctor);

    return jobject;
}
