//
// Created by Administrator on 2018/3/8.
//
#include <jni.h>
#include <string>
#include "phone_util.h"
#include "pcre/pcrecpp/include/pcrecpp.h"
#include "gperf/include/gperf.h"
#include "gmath/include/gmath.h"
#include <cinttypes>
#include <android/log.h>

#define LOG_TAG "PhoneUtilJNI"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

jstring charTojstring(JNIEnv *env, const char *pat);

char *jstringToChar(JNIEnv *env, jstring jstr);

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

    LOGE("calculation time: %"
                 PRIu64, ticks);

    return env->NewStringUTF("Hello from JNI LIBS!");
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jboolean Java_com_shixq_www_pcre2test_PhoneUtil_isPhoneMatch
        (JNIEnv *env, jclass thiz, jstring phone, jstring regex) {
    if (phone == NULL) {
        return false;
    }
    char *_phone = jstringToChar(env, phone);
    char *_regex = jstringToChar(env, regex);
    LOGE("phone is %s,regex is %s", _phone, _regex);
    pcrecpp::RE re(_regex);
    bool isMatch = re.FullMatch(_phone);
    return isMatch;
}

JNIEXPORT jstring Java_com_shixq_www_pcre2test_PhoneUtil_getPhonePrefix
        (JNIEnv *env, jclass thiz, jstring phone, jstring regex) {
    if (phone == NULL) {
        return env->NewStringUTF("");
    }
    char *_phone = jstringToChar(env, phone);
    char *_regex = jstringToChar(env, regex);
    pcrecpp::RE re(_regex);
    string prefix;
    string minPhone;
    re.FullMatch(_phone, &prefix, &minPhone);
    LOGE("phone prefix is %s", prefix.c_str());
    return env->NewStringUTF(prefix.c_str());
}

JNIEXPORT jstring Java_com_shixq_www_pcre2test_PhoneUtil_getMinPhone
        (JNIEnv *env, jclass thiz, jstring phone, jstring regex) {
    if (phone == NULL) {
        return env->NewStringUTF("");
    }
    char *_phone = jstringToChar(env, phone);
    char *_regex = jstringToChar(env, regex);
    pcrecpp::RE re(_regex);
    string prefix;
    string minPhone;
    re.FullMatch(_phone, &prefix, &minPhone);
    if (minPhone.empty()) {
        minPhone = _phone;
    }
    LOGE("phone un prefix is %s", minPhone.c_str());
    return env->NewStringUTF(minPhone.c_str());
}

char *jstringToChar(JNIEnv *env, jstring jstr) {
    char *rtn = "";
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

