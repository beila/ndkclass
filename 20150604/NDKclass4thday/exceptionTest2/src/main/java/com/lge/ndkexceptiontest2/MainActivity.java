package com.lge.ndkexceptiontest2;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("myexception");
    }

    native void doMakeException();

    public void makeException() throws Exception {
        throw new Exception("exception from java");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onButtonClick(View view) {
        doMakeException();
    }
}
