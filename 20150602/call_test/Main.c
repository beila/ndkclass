#include <jni.h>

JNIEXPORT jdouble JNICALL Java_Main_getCirclePI(JNIEnv *pEnv, jclass clazz) {
    jclass circleClass = (*pEnv)->FindClass(pEnv, "Circle");	// com\example\Circle

    jfieldID PI = (*pEnv)->GetStaticFieldID(pEnv, circleClass, "PI", "D");

    jdouble value = (*pEnv)->GetStaticDoubleField(pEnv, circleClass, PI);

    return value;
}

JNIEXPORT jdouble JNICALL Java_Main_getCircleArea(JNIEnv *pEnv, jclass clazz, jint r) {
    jclass circleClass = (*pEnv)->FindClass(pEnv, "Circle");	// com\example\Circle

    jmethodID getArea = (*pEnv)->GetStaticMethodID(pEnv, circleClass, "getArea", "(I)D");

    jdouble result = (*pEnv)->CallStaticDoubleMethod(pEnv, circleClass, getArea, r);

    return result;
}
