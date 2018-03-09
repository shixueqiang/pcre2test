package com.shixq.www.pcre2test;

/**
 * Created by shixq on 2018/3/8.
 */

public class PhoneUtil {
    public static String PHONE_REGEX = "^(86|\\+86|0086|852|\\+852|00852|125831|125832|125833)(\\d+)$";

    static {
        System.loadLibrary("phone_util");
    }

    public static native String stringFromJNI();

    public static native boolean isPhoneMatch(String phone, String regex);

    public static native String getPhonePrefix(String phone, String regex);

    public static native String getMinPhone(String phone, String regex);
}
