#include <android/bitmap.h>
#include <android/log.h>
#include "com_lge_imagetest_MainActivity.h"

#define LOG_TAG ("myimage")
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

void reverse_process(const AndroidBitmapInfo* info, void* pixel) {
    // RGB565 -> 16bit
    unsigned short *picBuf = (unsigned short*) pixel;

    int x, y;
    for (y = 0; y < info->height; ++y)
        for(x = 0; x < info->width; ++x) {
            picBuf[y*(info->width) + x] ^= 0xFFFF;
        }
}

JNIEXPORT void JNICALL Java_com_lge_imagetest_MainActivity_reverseImage
  (JNIEnv *env, jobject activity, jobject bitmap) {
    AndroidBitmapInfo info;
    int result = AndroidBitmap_getInfo(env, bitmap, &info);
    if (result != ANDROID_BITMAP_RESULT_SUCCESS) {
        LOGE("bitmap get info failed");
        return;
    }

    if (info.format != ANDROID_BITMAP_FORMAT_RGB_565) {
        LOGE("bitmap format error: %d", info.format);
        return;
    }

    LOGI("Bitmap size: %d x %d", info.width, info.height);

    void* pixel;
    result = AndroidBitmap_lockPixels(env, bitmap, &pixel);
    if (result != ANDROID_BITMAP_RESULT_SUCCESS) {
        LOGE("bitmap lock failed: %d", result);
        return;
    }

    reverse_process(&info, pixel);

    result = AndroidBitmap_unlockPixels(env, bitmap);
    if (result != ANDROID_BITMAP_RESULT_SUCCESS) {
        LOGE("bitmap unlock failed: %d", result);
        return;
    }

  }

