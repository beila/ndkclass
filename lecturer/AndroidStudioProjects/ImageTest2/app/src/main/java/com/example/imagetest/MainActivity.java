package com.example.imagetest;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends Activity {

    ImageView mImage;
    Bitmap mBitmap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mBitmap = BitmapFactory.decodeResource(getResources(), R.drawable.cat);
        mBitmap = mBitmap.copy(Bitmap.Config.RGB_565, true);

        mImage = (ImageView)findViewById(R.id.image_view);
        mImage.setImageBitmap(mBitmap);
    }

    public void onClick(View view) {
        reverseImage(mBitmap);
        mImage.setImageBitmap(mBitmap);
    }

    public native void reverseImage(Bitmap bitmap);
    static { System.loadLibrary("mybitmap"); }  // libmybitmap.so
}
