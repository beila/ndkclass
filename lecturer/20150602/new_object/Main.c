
// Main.c
#include "Main.h"

JNIEXPORT jobject JNICALL Java_Main_newMath
  (JNIEnv *pEnv, jclass clazz)
{
	// 1. 클래스 찾기
	jclass mathClass = (*pEnv)->FindClass(pEnv, "Math");

	// 2. 클래스의 생성자 찾기
	//  jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
	jmethodID ctor = (*pEnv)->GetMethodID(pEnv, mathClass, "<init>", "()V");

	// 3. 객체를 생성
	//  jobject (*NewObject)(JNIEnv*, jclass, jmethodID, ...); 
	jobject mathObject = (*pEnv)->NewObject(pEnv, mathClass, ctor);

	return mathObject;
}
