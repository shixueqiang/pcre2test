/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_shixq_www_pcre2test_PhoneUtil */

#ifndef _Included_com_shixq_www_pcre2test_PhoneUtil
#define _Included_com_shixq_www_pcre2test_PhoneUtil
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_shixq_www_pcre2test_PhoneUtil
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shixq_www_pcre2test_PhoneUtil_stringFromJNI
  (JNIEnv *, jclass);

/*
 * Class:     com_shixq_www_pcre2test_PhoneUtil
 * Method:    getPhonePrefix
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shixq_www_pcre2test_PhoneUtil_getPhonePrefix
        (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     com_shixq_www_pcre2test_PhoneUtil
 * Method:    getMinPhone
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shixq_www_pcre2test_PhoneUtil_getMinPhone
        (JNIEnv *, jclass, jstring, jstring);
#ifdef __cplusplus
}
#endif
/*
 * Class:     com_shixq_www_pcre2test_PhoneUtil
 * Method:    isPhoneMatch
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_shixq_www_pcre2test_PhoneUtil_isPhoneMatch
        (JNIEnv *, jclass, jstring, jstring);
#endif
