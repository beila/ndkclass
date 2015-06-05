package com.example.debugtest;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {

    static { System.loadLibrary("mydebug"); }   // libmydebug.so
    public static native void makeRuntimeError();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClick(View view) {
        makeRuntimeError();
    }
}
