package com.example.jnitoast;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends Activity {

    EditText mEdit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mEdit = (EditText)findViewById(R.id.edit_string);
    }

    public void onClick(View view)
    {
        switch(view.getId())
        {
            case R.id.btn_jnitost_short:
                displayToastShort(mEdit.getText());
                break;
            case R.id.btn_jnitost_long:
                displayToastLong(mEdit.getText());
                break;
        }
    }

    static { System.loadLibrary("jnitoast");}
    public native void displayToastShort(CharSequence s);
    public native void displayToastLong(CharSequence s);
}
