
// Hello.c
#include <stdio.h>	// for printf
#include <jni.h>	// for JNIEnv, jclass

// 네이티브의 함수명 작성 방법
// Java_<패키지명>_<클래스명>_<메서드명>(JNIEnv*, jclass);	-> 클래스 메서드
// Java_<패키지명>_<클래스명>_<메서드명>(JNIEnv*, jobject);	-> 인스턴스 메서드
//void printHelloJNI()
void Java_com_example_Hello_printHelloJNI(JNIEnv *pEnv, jclass clazz)
{
	printf("hello, jni from c\n");
}

