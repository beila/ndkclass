package com.example.threadtest;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("mythread");
    }

    public static void callback(int data) {
        Log.i("NativeThread", "callback:" + data);
    }

    native int startThread();

    native int stopThread();

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
        stopThread();
        super.onStop();
    }
}

