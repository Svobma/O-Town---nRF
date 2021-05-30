/*GPIO*/
#include <drivers/gpio.h>
#include "gpio.h"

/* 1000 msec = 1 sec */

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
#define LED0	DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN	DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(LED0_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: led0 devicetree alias is not defined"
#define LED0	""
#define PIN	0
#define FLAGS	0
#endif
/**/

//GPIO setup
const struct device *dev; 
int ret;
//

void gpio_init(){
    dev = device_get_binding(LED0);
	if (dev == NULL) {
		printk("error in dev=device_get_binding");
		return;
	}
	ret = gpio_pin_configure(dev, PIN, GPIO_OUTPUT | FLAGS);
	if (ret < 0) {
		return;
	}
}

