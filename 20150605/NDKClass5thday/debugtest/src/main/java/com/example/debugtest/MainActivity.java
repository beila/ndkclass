package com.example.debugtest;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("mydebug");
    }

    public static native void makeRuntimeError();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onButtonClick(View view) {
        makeRuntimeError();
    }

}
