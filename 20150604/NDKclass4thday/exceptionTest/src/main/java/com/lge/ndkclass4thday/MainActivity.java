package com.lge.ndkclass4thday;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onButtonClick(View view) {
        String log = ((EditText) findViewById(R.id.edit_text)).getText().toString();

        try {
            printLog(log);
        } catch (NonExistentStringException e) {
            Toast.makeText(MainActivity.this, e.getLocalizedMessage(), Toast.LENGTH_SHORT).show();
        }
    }

    static native void printLog(String log) throws NonExistentStringException;

    static { System.loadLibrary("mylog");}

}
