
# Android.mk

LOCAL_PATH:= $(call my-dir)

# for backlight_service
include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := liblog
LOCAL_SRC_FILES := backlight_service.c binder.c
LOCAL_MODULE := backlight_service
include $(BUILD_EXECUTABLE)

# for backlight_client
include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := liblog 
LOCAL_SRC_FILES := backlight_client.c binder.c
LOCAL_MODULE := backlight_client 
include $(BUILD_EXECUTABLE)
