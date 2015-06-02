
// Main.c
#include "Main.h"

JNIEXPORT jdouble JNICALL Java_Main_getCircleArea
  (JNIEnv *pEnv, jclass clazz, jint r)
{
	// 성능을 높히기 위해 캐시를 도입합니다.
	// static jclass circleClass = NULL;

	       jclass circleClass = NULL;		// LocalRef
	static jclass gCircleClass = NULL;		// GlobalRef

	if (gCircleClass == NULL)
	{
		circleClass = (*pEnv)->FindClass(pEnv, "Circle");

		// jobject (*NewGlobalRef)(JNIEnv*, jobject);
		gCircleClass = (*pEnv)->NewGlobalRef(pEnv, circleClass);
	}

	jmethodID getArea = (*pEnv)->GetStaticMethodID(pEnv, gCircleClass, "getArea", "(I)D");
	jdouble result = (*pEnv)->CallStaticDoubleMethod(pEnv, gCircleClass, getArea, r);

	return result;
}
