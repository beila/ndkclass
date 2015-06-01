#include "Type.h"

JNIEXPORT void JNICALL Java_Type_printBoolean
  (JNIEnv *pEnv, jclass clazz, jboolean a);

JNIEXPORT void JNICALL Java_Type_printByte
  (JNIEnv *pEnv, jclass clazz, jbyte a);

JNIEXPORT void JNICALL Java_Type_printChar
  (JNIEnv *pEnv, jclass clazz, jchar a);

JNIEXPORT void JNICALL Java_Type_printShort
  (JNIEnv *pEnv, jclass clazz, jshort a);

JNIEXPORT void JNICALL Java_Type_printInt
  (JNIEnv *pEnv, jclass clazz, jint a);

JNIEXPORT void JNICALL Java_Type_printLong
  (JNIEnv *pEnv, jclass clazz, jlong a);

JNIEXPORT void JNICALL Java_Type_printFloat
  (JNIEnv *pEnv, jclass clazz, jfloat a);

JNIEXPORT void JNICALL Java_Type_printDouble
  (JNIEnv *pEnv, jclass clazz, jdouble a);
