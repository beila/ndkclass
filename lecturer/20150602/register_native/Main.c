
// Main.c
#include <stdio.h>
#include <jni.h>

void printHelloWorld(JNIEnv* pEnv, jclass clazz) {
	printf("hello, world\n");
}

jstring getHelloWorld(JNIEnv* pEnv, jclass clazz) {
	return (*pEnv)->NewStringUTF(pEnv, "hello, world");
}

// 수동 바인딩을 위한 JNI_OnLoad 함수 작성
jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv* pEnv;
	// 1. JNIEnv 얻기
	// jint (*GetEnv)(JavaVM*, void**, jint);
	if((*vm)->GetEnv(vm, (void**)&pEnv, JNI_VERSION_1_6) != JNI_OK)
	{
		fprintf(stderr, "GetEnv Error\n");
		return JNI_ERR;
	}

//typedef struct {
//    const char* name;
//    const char* signature;
//    void*       fnPtr;
//} JNINativeMethod;

	// 2. 매핑 정보 설정
	JNINativeMethod mTable[2];

	mTable[0].name = "printHelloWorld";
	mTable[0].signature = "()V";
	mTable[0].fnPtr = printHelloWorld;
	
	mTable[1].name = "getHelloWorld";
	mTable[1].signature = "()Ljava/lang/String;";
	mTable[1].fnPtr = getHelloWorld;

	// 3. 클래스 정보 찾음
	jclass mainClass = (*pEnv)->FindClass(pEnv, "com/example/Main");

	// 4. 메서드와 함수를 바인딩 합니다.
	// jint (*RegisterNatives)(JNIEnv*, jclass, const JNINativeMethod*, jint);
	(*pEnv)->RegisterNatives(pEnv, mainClass, mTable, 2);

	// 5. 성공했다면 반드시 JNI 버전을 리턴해야 합니다.
	return JNI_VERSION_1_6;
}
