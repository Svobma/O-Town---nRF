/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <settings/settings.h>
#include "service.c"


//Zephyr bluetooth stack: https://docs.zephyrproject.org/latest/guides/bluetooth/bluetooth-arch.html

void main(void)
{
	int err;
	err = bt_enable(NULL);
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
		return;
	}

	//Initialize service, start advertising & initialize callback
	bt_ready();  
	
	//GPIO initializaiton
	gpio_init();

	while (1) {
		k_sleep(K_SECONDS(1));
	}
}
