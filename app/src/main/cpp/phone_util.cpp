//
// Created by Administrator on 2018/3/8.
//
#include <jni.h>
#include <string>
#include "phone_util.h"
#include "pcre/pcrecpp/include/pcrecpp.h"
#include "gperf/include/gperf.h"
#include "gmath/include/gmath.h"
#include <cstring>
#include <cinttypes>
#include <android/log.h>
#define LOG_TAG "PhoneUtilJNI"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

jstring charTojstring(JNIEnv* env, const char* pat);
char* jstringToChar(JNIEnv* env, jstring jstr);

JNIEXPORT jstring Java_com_shixq_www_pcre2test_PhoneUtil_stringFromJNI
        (JNIEnv *env, jclass thiz) {
    // Just for simplicity, we do this right away; correct way would do it in
    // another thread...
    auto ticks = GetTicks();

    for (auto exp = 0; exp < 32; ++exp) {
        volatile unsigned val = gpower(exp);
        (void) val;  // to silence compiler warning
    }
    ticks = GetTicks() - ticks;

    LOGE("calculation time: %" PRIu64, ticks);

    return env->NewStringUTF("Hello from JNI LIBS!");
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jboolean Java_com_shixq_www_pcre2test_PhoneUtil_isPhoneMatch
        (JNIEnv *env, jclass thiz, jstring phone, jstring regex) {
    const char* _phone = jstringToChar(env, phone);
    const char* _regex = jstringToChar(env, regex);
    LOGE("phone is %s,regex is %s", _phone, _regex);
    pcrecpp::RE re(_regex);
    bool isMatch = re.FullMatch(_phone);
    return isMatch;
}

JNIEXPORT jstring Java_com_shixq_www_pcre2test_PhoneUtil_getPhonePrefix
        (JNIEnv *env, jclass thiz, jstring phone, jstring regex) {

}

JNIEXPORT jstring Java_com_shixq_www_pcre2test_PhoneUtil_getMinPhone
        (JNIEnv *env, jclass thiz, jstring phone, jstring regex) {

}

jstring charTojstring(JNIEnv* env, const char* pat) {
    //定义java String类 strClass
    jclass strClass = (env)->FindClass("Ljava/lang/String;");
    //获取String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    //建立byte数组
    jbyteArray bytes = (env)->NewByteArray(strlen(pat));
    //将char* 转换为byte数组
    (env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*) pat);
    // 设置String, 保存语言类型,用于byte数组转换至String时的参数
    jstring encoding = (env)->NewStringUTF("GB2312");
    //将byte数组转换为java String,并输出
    return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
}

char* jstringToChar(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char*) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

