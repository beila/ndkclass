package com.example.lge;

public class Hello {
    public static native void printHello();
    public        native void printWorld();

    static { System.loadLibrary("hello"); }

    public static void main(String[] args) {
	printHello();
	new Hello().printWorld();
    }
}
