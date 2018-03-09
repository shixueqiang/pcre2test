package com.shixq.www.pcre2test;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {
    private static String TAG = "PhoneUtilJNI";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.e(TAG, PhoneUtil.stringFromJNI());
        Log.e(TAG, "" + PhoneUtil.isPhoneMatch("1358622a", PhoneUtil.PHONE_REGEX));
        Log.e(TAG, "" + PhoneUtil.isPhoneMatch("+86186285", PhoneUtil.PHONE_REGEX));
    }
}
