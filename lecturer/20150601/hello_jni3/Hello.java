
// Hello.java
package com.example;

public class Hello
{
	// native method
	public native String getHelloWorld();

	// load libary
	static { System.loadLibrary("hello"); }	// libhello.so

	public static void main(String[] args)
	{
		Hello hello = new Hello();
		String helloWorld = hello.getHelloWorld();

		System.out.println(helloWorld);
	}
}
