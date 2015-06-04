LOCAL_PATH:= $(call my-dir)

# for led_service

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := liblog
LOCAL_SRC_FILES := led_service.c binder.c
LOCAL_MODULE := led_service
include $(BUILD_EXECUTABLE)

# for led_client

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := liblog
LOCAL_SRC_FILES := led_client.c binder.c
LOCAL_MODULE := led_client
include $(BUILD_EXECUTABLE)
