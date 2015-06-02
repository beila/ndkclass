
// Array.c
#include "Array.h"

void Java_Array_printIntArray(JNIEnv *pEnv, jclass clazz, jintArray arr)
{
	// jsize (*GetArrayLength)(JNIEnv*, jarray);
	int len = (*pEnv)->GetArrayLength(pEnv, arr); // 태그 이동 방법: g+], 복귀 방법: CTRL + T

	// jint* (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
	jint* pArr = (*pEnv)->GetIntArrayElements(pEnv, arr, 0);

	int i;
	for(i = 0; i < len; i++)
		printf("%d ", pArr[i]);
	printf("\n");

	// void (*ReleaseIntArrayElements)(JNIEnv*, jintArray, jint*, jint);

	(*pEnv)->ReleaseIntArrayElements(pEnv, arr, pArr, 0);
}

