
// Array.c
#include <stdlib.h>	// for malloc

#include "Array.h"

JNIEXPORT jintArray JNICALL Java_Array_makeIntArray
  (JNIEnv *pEnv, jclass clazz, jint len)
{
	// jintArray (*NewIntArray)(JNIEnv*, jsize); 
	jintArray intArr = (*pEnv)->NewIntArray(pEnv, len);

	// jint tempArr[len] = { 1,2,3,4,5 };
	jint* pArr = (jint*)malloc(sizeof(jint) * len);
	int i;
	for(i = 0; i < len; i++)
		pArr[i] = i+1;

	//void (*SetIntArrayRegion)(JNIEnv*, jintArray, jsize, jsize, const jint*); 
	(*pEnv)->SetIntArrayRegion(pEnv, intArr, 0, len, pArr);

	free(pArr);

	return intArr;
}

JNIEXPORT jdoubleArray JNICALL Java_Array_makeDoubleArray
  (JNIEnv *pEnv, jclass clazz, jint len)
{
	jdoubleArray intArr = (*pEnv)->NewDoubleArray(pEnv, len);

	jdouble* pArr = (jdouble*)malloc(sizeof(jdouble) * len);
	int i;
	for(i = 0; i < len; i++)
		pArr[i] = i+1;

	(*pEnv)->SetDoubleArrayRegion(pEnv, intArr, 0, len, pArr);

	free(pArr);
	return intArr;
}
