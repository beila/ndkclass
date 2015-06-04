package com.lge.backlightapp;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("backlight");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onButtonBright(View view) {
        setBrightness(255);
    }

    public void onButtonDark(View view) {
        setBrightness(10);
    }

    native void setBrightness(int i);

}
