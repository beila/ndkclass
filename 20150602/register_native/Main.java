package com.example;

public class Main {
    public static native void printHelloWorld();
    public static native String getHelloWorld();

    static { System.loadLibrary("hello"); }

    public static void main(String[] args) {
	printHelloWorld();
	System.out.println(getHelloWorld());
    }
}
