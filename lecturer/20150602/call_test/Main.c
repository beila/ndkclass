
// Main.c
#include "Main.h"
JNIEXPORT jdouble JNICALL Java_Main_getCirclePI
  (JNIEnv *pEnv, jclass clazz)
{
	// 1. 클래스 찾기
	jclass circleClass = (*pEnv)->FindClass(pEnv, "Circle");

	// 2. 멤버 변수 찾기
	// jfieldID (*GetStaticFieldID)(JNIEnv*, jclass, const char*, const char*);
	jfieldID PI = (*pEnv)->GetStaticFieldID(pEnv, circleClass, "PI", "D");

	// 3. 멤버 변수의 값 읽어오기
	// jdouble     (*GetStaticDoubleField)(JNIEnv*, jclass, jfieldID);
	jdouble value = (*pEnv)->GetStaticDoubleField(pEnv, circleClass, PI);

	return value;
}

JNIEXPORT jdouble JNICALL Java_Main_getCircleArea
  (JNIEnv *pEnv, jclass clazz, jint r)
{
	// 1. 클래스 찾기
	jclass circleClass = (*pEnv)->FindClass(pEnv, "Circle");
	                      // ex) com.example.Circle -> com\example\Circle

	// 2. 메서드 찾기
	//  jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
	jmethodID getArea = (*pEnv)->GetStaticMethodID(pEnv, circleClass, "getArea", "(I)D");
	
	// 3. 정적 메서드 호출
	// jdouble (*CallStaticDoubleMethod)(JNIEnv*, jclass, jmethodID, ...);
	jdouble result = (*pEnv)->CallStaticDoubleMethod(pEnv, circleClass, getArea, r);

	return result;
}
