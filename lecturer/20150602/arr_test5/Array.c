
// Array.c
#include "Array.h"

JNIEXPORT jobjectArray JNICALL Java_Array_make2DIntArray
  (JNIEnv *pEnv, jclass clazz, jint row, jint col)
{
	jobjectArray objectArray;

	// 1. 원소의 클래스를 찾음
	//  jclass (*FindClass)(JNIEnv*, const char*); 
	jclass intArrayClass = (*pEnv)->FindClass(pEnv, "[I");

	// 2. 클래스의 정보로부터 배열을 생성
	// jobjectArray (*NewObjectArray)(JNIEnv*, jsize, jclass, jobject); 
	objectArray = (*pEnv)->NewObjectArray(pEnv, row, intArrayClass, NULL);

	// 3. 원소를 초기화
	int i, j;
	for(i = 0; i < row; i++)
	{

		jint tempArr[128] = { 0, };
		// jintArray     (*NewIntArray)(JNIEnv*, jsize);	
		jintArray intArr = (*pEnv)->NewIntArray(pEnv, col);

		// void (*SetIntArrayRegion)(JNIEnv*, jintArray, jsize, jsize, const jint*);
		(*pEnv)->SetIntArrayRegion(pEnv, intArr, 0, col, tempArr);

		// void (*SetObjectArrayElement)(JNIEnv*, jobjectArray, jsize, jobject); 
		(*pEnv)->SetObjectArrayElement(pEnv, objectArray, i, intArr);

		// void (*DeleteLocalRef)(JNIEnv*, jobject);
		(*pEnv)->DeleteLocalRef(pEnv, intArr);
	}

	return objectArray;
}

