#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <zephyr.h>
#include <stdint.h> //pointer to integer

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>

#include "service.h"
#include "gpio.c"

//Zephyr's guide https://docs.zephyrproject.org/latest/reference/bluetooth/gatt.html

//Unique Universal ID of service
static struct bt_uuid_128 otown_uuid = BT_UUID_INIT_128("2344118e-f29b-4961-bc74-82a5249c0d23");
	// 0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
	// 0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

static struct bt_uuid_128 vnd_enc_uuid = BT_UUID_INIT_128("b5c1c0f1-7681-4c7f-b5af-559d43a8e5c8");
	// 0xf1, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
	// 0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

//Initial value of the service
static uint8_t otown_value[] = { 'O', ' ', 'T', 'o', 'w', 'n' };


static ssize_t read_otown(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			void *buf, uint16_t len, uint16_t offset)
{
    //pointer to data in GATT structure
	const char *value = attr->user_data;

	return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
				 strlen(value));
}
//Callback function of write command
static ssize_t write_otown(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			 const void *buf, uint16_t len, uint16_t offset,
			 uint8_t flags)
{
	uint8_t *value = attr->user_data;
		
	if (offset + len > sizeof(otown_value)) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	memcpy(value + offset, buf, len);

	int value_int = (int)*value; 
	//RSSI LED trigger
	if(value_int >= 9){
		gpio_pin_set(dev, PIN, true);
		printk("value_int = %i \n",value_int);
	}
	else{
		gpio_pin_set(dev, PIN, false);
		printk("else \n");
	}

	//Print value
	printk("Value = ");
	for (size_t i = 0; i < len; i++){
		printk("%c", *value++);	
	}   printk("\n");
	
	return len;
}

//Client Characteristic Configuration.
static void vnd_ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value) //Client Characterictics Configuration
{
	
}


/* Primary Service Declaration */
BT_GATT_SERVICE_DEFINE(otown_svc, //create a struct with _name
	BT_GATT_PRIMARY_SERVICE(&otown_uuid), //Main UUID
	BT_GATT_CHARACTERISTIC(&vnd_enc_uuid.uuid, //Charasteristics attribute UUID
			       BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE, //Properties
			       BT_GATT_PERM_READ_ENCRYPT | //Permission
			       BT_GATT_PERM_WRITE_ENCRYPT, //Permission
			       read_otown, write_otown, otown_value), //Callback functions and value
	BT_GATT_CCC(vnd_ccc_cfg_changed, //Client Configuration Configuration
		    BT_GATT_PERM_READ | BT_GATT_PERM_WRITE_ENCRYPT)
);

//Advertising address
static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
    //BT_DATA_BYTES(BT_DATA_UUID16_ALL), //Short UUIDs, I think used for standardized characteristics
	BT_DATA_BYTES(BT_DATA_UUID128_ALL, //Our UUID
		      0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
		      0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12),
};

static void connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		printk("Connection failed (err 0x%02x)\n", err);
	} else {
		printk("Connected\n");
	}
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	printk("Disconnected (reason 0x%02x)\n", reason);
}

static struct bt_conn_cb conn_callbacks = {
	.connected = connected,
	.disconnected = disconnected,
};

static void bt_ready(void)
{
	int err;

	printk("Bluetooth initialized\n");

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	bt_conn_cb_register(&conn_callbacks);

	err = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0); //Advertising parameters, data to be advertised and used for response
	if (err) {
		printk("Advertising failed to start (err %d)\n", err);
		return;
	}
	printk("Advertising successfully started\n");
}


