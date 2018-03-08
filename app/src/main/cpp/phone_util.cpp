//
// Created by Administrator on 2018/3/8.
//
#include <jni.h>
#include <string>

extern "C"
jstring
Java_com_shixq_www_pcre2test_PhoneUtil_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

