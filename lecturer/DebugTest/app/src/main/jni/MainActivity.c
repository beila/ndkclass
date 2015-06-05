
// MainActivity.c
#include "MainActivity.h"

int foo() { 
	int *p = 0;
	*p = 20;	// null reference -> segmentation fault

	return 0;
}

	JNIEXPORT void JNICALL Java_com_example_debugtest_MainActivity_makeRuntimeError
(JNIEnv *pEnv, jclass clazz)
{
	int n = foo();
}


