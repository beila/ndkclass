package com.example;

public class Hello {
    public native String getHelloWorld();

    static { System.loadLibrary("hello"); }

    public static void main(String[] args) {
	Hello hello = new Hello();
	String helloWorld = hello.getHelloWorld();
	System.out.println(helloWorld);
    }
}
