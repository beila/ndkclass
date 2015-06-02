#include <stdio.h>
#include <jni.h>

void Java_Array_printIntArray(JNIEnv *pEnv, jclass clazz, jintArray arr) {
    int len = (*pEnv)->GetArrayLength(pEnv, arr);

    jint* pArr = (*pEnv)->GetIntArrayElements(pEnv, arr, 0);

    int i;
    for (i = 0; i < len; ++i) {
	printf("%d ", pArr[i]);
    }
    printf("\n");

    (*pEnv)->ReleaseIntArrayElements(pEnv, arr, pArr, 0);
}
