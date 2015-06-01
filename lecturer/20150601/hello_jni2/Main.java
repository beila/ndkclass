
// Main.java
package com.example.lge;

public class Main
{
	// 네이티브 메서드와 공유 라이브러리 로딩 코드 작성
	public static native void printHelloWorld();
	static { System.loadLibrary("hello"); }	// libhello.so

	public static void main(String[] args)
	{
		printHelloWorld();
	}
}
