package com.example.threadtest;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {
    static { System.loadLibrary("mythread"); }  // libmythread.so
    public native int startThread();
    public native int stopThread();

    public static void callback(int data) {
        String text = "callback: " + data;
        Log.i("NativeThread", text);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    protected void onResume() {
        super.onResume();
        startThread();
    }

    @Override
    protected void onStop() {
        super.onStop();
        stopThread();
    }
}
