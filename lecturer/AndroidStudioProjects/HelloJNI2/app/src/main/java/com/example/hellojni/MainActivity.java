package com.example.hellojni;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView text = (TextView)findViewById(R.id.text_view);
        text.setText(getHelloJNI());    // Hello, JNI
    }

    public static native String getHelloJNI();
    static { System.loadLibrary("hello"); } // libhello.so
}
