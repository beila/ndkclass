#include "com_example_debugtest_MainActivity.h"

int foo() {
	int *p = 0;
	*p = 20; // ==>> segmentation fault
	return 0;
}

JNIEXPORT void JNICALL Java_com_example_debugtest_MainActivity_makeRuntimeError
  (JNIEnv *env, jclass clazz) {
	  int n = foo();
  }
