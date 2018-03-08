package com.shixq.www.pcre2test;

/**
 * Created by shixq on 2018/3/8.
 */

public class PhoneUtil {
    static {
        System.loadLibrary("phone_util");
    }

    public static native String stringFromJNI();
}
