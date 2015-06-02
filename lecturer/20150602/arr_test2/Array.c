
#include "Array.h"


JNIEXPORT void JNICALL Java_Array_printDoubleArray
  (JNIEnv *pEnv, jclass clazz, jdoubleArray arr)
{
	int len = (*pEnv)->GetArrayLength(pEnv, arr);

	jdouble* pArr = (*pEnv)->GetDoubleArrayElements(pEnv, arr, 0);
	if (pArr == NULL)
		return;

	int i;
	for(i = 0; i < len; i++)
		printf("%f ", pArr[i]);
	printf("\n");

	(*pEnv)->ReleaseDoubleArrayElements(pEnv, arr, pArr, 0);
}

