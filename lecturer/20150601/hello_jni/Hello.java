
// Hello.java
package com.example;

public class Hello
{
	// 네이티브 메서드와 공유 라이브러리를 로딩
	public static native void printHelloJNI();
	static { System.loadLibrary("hello"); }	// libhello.so

	public static void main(String[] args)
	{
		printHelloJNI();	// or Hello.printHelloJNI();
	}
}
