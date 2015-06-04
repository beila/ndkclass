package com.lge.imagetest;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("myimage");
    }

    private Bitmap bitmap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.pond_by_paradise);
        bitmap = bitmap.copy(Bitmap.Config.RGB_565, true);
        ((ImageView) findViewById(R.id.imageView)).setImageBitmap(bitmap);
    }

    public void onButtonClick(View view) {
        reverseImage(bitmap);
        ((ImageView) findViewById(R.id.imageView)).setImageBitmap(bitmap);
    }

    native void reverseImage(Bitmap bitmap);
}
