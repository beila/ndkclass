
// Hello.java
package com.example.lge;

public class Hello 
{
	public static native void printHello();	// class method
	public        native void printWorld();	// instance method

	static { System.loadLibrary("hello"); }	// libhello.so

	public static void main(String[] args)
	{
		printHello();
		new Hello().printWorld();
	}
}
