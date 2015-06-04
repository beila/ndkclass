package com.example.root.helloworld;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // TextView txt = (TextView)findViewById(R.id.)
    }

    // static { System.loadLibrary("hello");}  // libhello.so
    // public static native void getHelloJNI();

}
