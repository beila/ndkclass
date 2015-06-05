#include <android/log.h>
#define LOG_TAG ("NATIVE_ACTIVITY")
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "android_native_app_glue.h"

void android_main(struct android_app* app) {
    // Make sure glue isn't stripped.
    app_dummy();

	while(1) {
		int ident;
		int events;
		struct android_poll_source *source;

		while((ident = ALooper_pollAll(-1, NULL, &events, (void**)&source)) >= 0) {
			if (source != NULL) {
				LOGV("poll with source");
				source->process(app, source);
			}

			if (app->destroyRequested != 0) {
				return;
			}
		}
	}
}
