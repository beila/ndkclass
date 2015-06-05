
// led_client.c

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <jni.h>

#include "binder.h"
uint32_t svcmgr_lookup(struct binder_state *bs, uint32_t target, const char *name)
{
	uint32_t handle;
	unsigned iodata[512/4];
	struct binder_io msg, reply;

	bio_init(&msg, iodata, sizeof(iodata), 4);
	bio_put_uint32(&msg, 0);  // strict mode header
	bio_put_string16_x(&msg, SVC_MGR_NAME);
	bio_put_string16_x(&msg, name);

	if (binder_call(bs, &msg, &reply, target, SVC_MGR_CHECK_SERVICE))
		return 0;

	handle = bio_get_ref(&reply);
	if (handle)
		binder_acquire(bs, handle);

	binder_done(bs, &msg, &reply);
	return handle;
}

void backlight_on(struct binder_state *bs, uint32_t target) {
	unsigned iodata[512/4];
	struct binder_io msg, reply;
	bio_init(&msg, iodata, sizeof(iodata), 4);
	binder_call(bs, &msg, &reply, target, 1);
}

void backlight_off(struct binder_state *bs, uint32_t target) {
	unsigned iodata[512/4];
	struct binder_io msg, reply;
	bio_init(&msg, iodata, sizeof(iodata), 4);
	binder_call(bs, &msg, &reply, target, 2);
}

int handle = 0;
struct binder_state *bs = 0;

void Java_com_example_backlightapp_MainActivity_setBacklight
(JNIEnv *pEnv, jobject thiz, jint brightness) {

	if(handle == 0)
	{
		bs = binder_open(128*1024);
		if (!bs) {
			fprintf(stderr, "failed to open binder driver\n");
			return -1;
		}

		handle = svcmgr_lookup(bs, BINDER_SERVICE_MANAGER, "com.example.backlight_service");
	}

	if(brightness == 255)
		backlight_on(bs, handle);
	else
		backlight_off(bs, handle);
}



