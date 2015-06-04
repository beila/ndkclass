package com.example.exceptiontest2;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void makeException() throws Exception {
        throw new Exception("exception from Java");
    }

    public void onClick(View view) {
        doMakeExeption();
    }

    public native void doMakeExeption();
    static { System.loadLibrary("myexception"); }   // libmyexception.so
}
