
#define  LOG_TAG    ("com.example.imagetest")

// MainActivity.c
#include <jni.h>

#include <android/bitmap.h>
#include <android/log.h>
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#include "MainActivity.h"

void reverse_process(const AndroidBitmapInfo *info, void *pixel)
{
	// RGB565 -> 16bit 
	unsigned short *picBuf = (unsigned short*)pixel;

	int x, y;
	for(y = 0; y < info->height; y++)
	{
		for(x = 0; x < info->width; x++)
			picBuf[y*(info->width) + x] ^= 0xFFFF;
	}
}


JNIEXPORT void JNICALL Java_com_example_imagetest_MainActivity_reverseImage
  (JNIEnv *pEnv, jobject thiz, jobject bitmap)
{
	AndroidBitmapInfo info;

	if (AndroidBitmap_getInfo(pEnv, bitmap, &info) < 0)
	{
		LOGE("AndroidBitmap_getInfo Error");
		return;
	}

	if (info.format != ANDROID_BITMAP_FORMAT_RGB_565)
	{
		LOGE("NOT ANDROID_BITMAP_FORMAT_RGB_565");
		return;
	}

	LOGI("Bitmap: %d x %d", info.width, info.height);

	//int AndroidBitmap_lockPixels(JNIEnv* env, jobject jbitmap, void** addrPtr) 
	void* pixel;
	if (AndroidBitmap_lockPixels(pEnv, bitmap, &pixel) < 0)
	{
		LOGE("AndroidBitmap_lockPixels Error");
		return;
	}

	reverse_process(&info, pixel);

	//  int AndroidBitmap_unlockPixels(JNIEnv* env, jobject jbitmap);
	AndroidBitmap_unlockPixels(pEnv, bitmap);
}







