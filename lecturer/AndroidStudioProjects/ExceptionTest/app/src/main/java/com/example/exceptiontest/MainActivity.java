package com.example.exceptiontest;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

    EditText mEdit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mEdit = (EditText)findViewById(R.id.edit_text);
    }

    public void onClick(View view) {
        String log = mEdit.getText().toString();

        try {
            printLog(log);  // not Logcat
        } catch(NotExistStringException e) {
            Toast.makeText(this, e.getMessage(), Toast.LENGTH_LONG).show();
        }
    }

    public static native void printLog(String log)
            throws NotExistStringException;
    static { System.loadLibrary("mylog"); } // libmylog.so


}
