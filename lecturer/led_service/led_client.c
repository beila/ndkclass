
// led_client.c

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

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

void led_on(struct binder_state *bs, uint32_t target) {
    unsigned iodata[512/4];
    struct binder_io msg, reply;
    bio_init(&msg, iodata, sizeof(iodata), 4);
    binder_call(bs, &msg, &reply, target, 1);
}

void led_off(struct binder_state *bs, uint32_t target) {
    unsigned iodata[512/4];
    struct binder_io msg, reply;
    bio_init(&msg, iodata, sizeof(iodata), 4);
    binder_call(bs, &msg, &reply, target, 2);
}

int main() {
    struct binder_state *bs = binder_open(128*1024);
    if (!bs) {
        fprintf(stderr, "failed to open binder driver\n");
        return -1;
    }

    uint32_t handle
		= svcmgr_lookup(bs, BINDER_SERVICE_MANAGER, "com.example.led_service");

	while(1) {
		getchar(); led_on(bs, handle);
		getchar(); led_off(bs, handle);
	}
    return 0;
}
