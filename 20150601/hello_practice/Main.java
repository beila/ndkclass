package com.example.lge;

public class Main {
    static { System.loadLibrary("hello"); }

    static native void printHelloWorld();

    public static void main(String[] args) {
	printHelloWorld();
    }
}
