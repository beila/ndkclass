#include "com_lge_backlightapp_MainActivity.h"

#include <android/log.h>

#define LOG_TAG ("backlight")
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

JNIEXPORT void JNICALL Java_com_lge_backlightapp_MainActivity_setBrightness
  (JNIEnv *env, jobject thiz, jint brightness) {
    int backlight_fd = open("/sys/class/backlight/tegra-dsi-backlight.0/brightness", O_RDWR);
//    int backlight_fd = open("/sys/devices/platform/tegra-dsi-backlight.0/backlight/tegra-dsi-backlight.0/brightness", O_RDWR);
//    int backlight_fd = open("/sys/class/leds/lcd-backlight/brightness", O_RDWR);  // G Watch R
    if (backlight_fd < 0) {
        LOGE("open failure: %s", strerror(errno));
        return;
    }

    char buf[10];
    sprintf(buf, "%d", brightness);
    int result = write(backlight_fd, buf, strlen(buf));
    if (result < 0) {
        LOGE("write failure: %s", strerror(errno));
        return;
    }
  }
