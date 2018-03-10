LOCAL_PATH:= $(call my-dir)

libpcre_src_files := \
    pcre/dist2/src/pcre2_auto_possess.c \
    pcre/dist2/src/pcre2_compile.c \
    pcre/dist2/src/pcre2_config.c \
    pcre/dist2/src/pcre2_context.c \
    pcre/dist2/src/pcre2_dfa_match.c \
    pcre/dist2/src/pcre2_error.c \
    pcre/dist2/src/pcre2_find_bracket.c \
    pcre/dist2/src/pcre2_maketables.c \
    pcre/dist2/src/pcre2_match.c \
    pcre/dist2/src/pcre2_match_data.c \
    pcre/dist2/src/pcre2_jit_compile.c \
    pcre/dist2/src/pcre2_newline.c \
    pcre/dist2/src/pcre2_ord2utf.c \
    pcre/dist2/src/pcre2_pattern_info.c \
    pcre/dist2/src/pcre2_serialize.c \
    pcre/dist2/src/pcre2_string_utils.c \
    pcre/dist2/src/pcre2_study.c \
    pcre/dist2/src/pcre2_substitute.c \
    pcre/dist2/src/pcre2_substring.c \
    pcre/dist2/src/pcre2_tables.c \
    pcre/dist2/src/pcre2_ucd.c \
	pcre/dist2/src/pcre2_valid_utf.c \
	pcre/dist2/src/pcre2_xclass.c \
	pcre/dist2/src/pcre2_chartables.c

libpcrecpp_src_files := \
    pcre/pcrecpp/pcrecpp.cc \
    pcre/pcrecpp/pcre_scanner.cc \
    pcre/pcrecpp/pcre_stringpiece.cc

libpcre_cflags := \
    -DHAVE_CONFIG_H \
    -Wno-self-assign \
    -Wno-unused-parameter \

# === libpcre targets ===

#include $(CLEAR_VARS)
#LOCAL_MODULE := libpcre2
#LOCAL_CFLAGS += $(libpcre_cflags)
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/pcre/include
#LOCAL_SRC_FILES := $(libpcre_src_files)
#LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)
#include $(BUILD_HOST_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libpcre2
LOCAL_CFLAGS += $(libpcre_cflags)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/pcre/include \
					$(LOCAL_PATH)/pcre/include_internal
LOCAL_SRC_FILES := $(libpcre_src_files)
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)
include $(BUILD_STATIC_LIBRARY)

#include $(CLEAR_VARS)
#LOCAL_MODULE := libpcre2
#LOCAL_CFLAGS += $(libpcre_cflags)
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/pcre/include
#LOCAL_SRC_FILES := $(libpcre_src_files)
#LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)
#include $(BUILD_SHARED_LIBRARY)

# === libpcrecpp targets ===

include $(CLEAR_VARS)
LOCAL_MODULE := libpcrecpp
LOCAL_CFLAGS += $(libpcre_cflags)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/pcre/pcrecpp/include \
					$(LOCAL_PATH)/pcre/include
LOCAL_CPP_EXTENSION := .cc
LOCAL_SRC_FILES := $(libpcrecpp_src_files)
#LOCAL_SHARED_LIBRARIES := libpcre2
LOCAL_STATIC_LIBRARIES := libpcre2
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)
include $(BUILD_SHARED_LIBRARY)
