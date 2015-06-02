#include <jni.h>

JNIEXPORT jdouble JNICALL Java_Main_getCircleArea(JNIEnv *pEnv, jclass clazz, jint r) {
    jclass circleClass = NULL;
    static jclass gCircleClass = NULL;

    if (gCircleClass == NULL) {
	circleClass = (*pEnv)->FindClass(pEnv, "Circle");
	gCircleClass = (*pEnv)->NewGlobalRef(pEnv, circleClass);
    }

    jmethodID getArea = (*pEnv)->GetStaticMethodID(pEnv, gCircleClass, "getArea", "(I)D");

    jdouble result = (*pEnv)->CallStaticDoubleMethod(pEnv, gCircleClass, getArea, r);

    return result;
}
