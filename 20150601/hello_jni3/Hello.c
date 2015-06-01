#include <jni.h>

jstring Java_com_example_Hello_getHelloWorld(JNIEnv *pEnv, jobject thiz) {
    (*pEnv)->NewStringUTF(pEnv, "hello, world");
}
