
// Array.c
#include <stdio.h>
#include <stdlib.h>

#include "Array.h"

JNIEXPORT void JNICALL Java_Array_print2DIntArray
  (JNIEnv *pEnv, jclass clazz, jobjectArray arr)
{
	int len = (*pEnv)->GetArrayLength(pEnv, arr);

	jint(*pArr)[3] = (int(*)[3])malloc(sizeof(jint) * len * 3);

	
	int i, j;
	for(i = 0; i < len; i++)	// 행에 접근
	{
		// jobject (*GetObjectArrayElement)(JNIEnv*, jobjectArray, jsize);
		jintArray intArr = (*pEnv)->GetObjectArrayElement(pEnv, arr, i);

		// jint* (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
		jint* tempArr = (*pEnv)->GetIntArrayElements(pEnv, intArr, 0);

		for(j = 0; j < 3; j++)
			pArr[i][j] = tempArr[j];

		// void (*ReleaseIntArrayElements)(JNIEnv*, jintArray, jint*, jint);
		(*pEnv)->ReleaseIntArrayElements(pEnv, intArr, tempArr, 0);
		(*pEnv)->DeleteLocalRef(pEnv, intArr);
	}

	for(i = 0; i < len; i++)
	{
		for(j = 0; j < 3; j++)
			printf("%d ", pArr[i][j]);
		printf("\n");
	}

	free(pArr);
	(*pEnv)->DeleteLocalRef(pEnv, arr);
}
