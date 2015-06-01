package com.example;

public class Hello {
    public static native void printHelloJni();

    static {
	System.loadLibrary("hello");
    }

    public static void main(String[] args) {
	printHelloJni();
    }
}
