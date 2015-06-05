
// led_service.c

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "binder.h"
int svcmgr_publish(struct binder_state *bs, uint32_t target,
		const char *name, void *ptr)
{
	int status;
	unsigned iodata[512/4];
	struct binder_io msg, reply;

	bio_init(&msg, iodata, sizeof(iodata), 4);
	bio_put_uint32(&msg, 0);  // strict mode header
	bio_put_string16_x(&msg, SVC_MGR_NAME);
	bio_put_string16_x(&msg, name);
	bio_put_obj(&msg, ptr);

	if (binder_call(bs, &msg, &reply, target, SVC_MGR_ADD_SERVICE))
		return -1;
	status = bio_get_uint32(&reply);
	binder_done(bs, &msg, &reply);
	return status;
}

void backlight_on()
{
	int backlight_fd =
		open("/sys/devices/platform/tegra-dsi-backlight.0/backlight/tegra-dsi-backlight.0/brightness", O_RDWR);
	printf("backlight_fd = %d", backlight_fd);

	if (backlight_fd < 0) return;

	char buff[10];
	sprintf(buff, "%d", 255);
	write(backlight_fd, buff, strlen(buff));

	close(backlight_fd);
}

void backlight_off()
{
	int backlight_fd =
		open("/sys/devices/platform/tegra-dsi-backlight.0/backlight/tegra-dsi-backlight.0/brightness", O_RDWR);

	printf("backlight_fd = %d", backlight_fd);
	if (backlight_fd < 0) return;

	char buff[10];
	sprintf(buff, "%d", 10);
	write(backlight_fd, buff, strlen(buff));

	close(backlight_fd);
}


int my_handler(struct binder_state *bs, struct binder_transaction_data *txn,
                              struct binder_io *msg, struct binder_io *reply)
{
	printf("[led_service] my_handler\n");

	switch(txn->code)
	{
		case 1: backlight_on(); break;
		case 2: backlight_off(); break;
	}
	return 0;
}

unsigned token;
int main()
{
	struct binder_state *bs = binder_open(128*1024);
	if (!bs) {
		fprintf(stderr, "failed to open binder driver\n");
		return -1;
	}

	svcmgr_publish(bs, BINDER_SERVICE_MANAGER, "com.example.backlight_service", &token);
	binder_loop(bs, my_handler);
	return 0;
}
