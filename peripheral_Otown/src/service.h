/** @file
 *  @brief Service sample*/

#ifdef __cplusplus
extern "C" {
#endif

//Callback of bluetooth read
static ssize_t read_otown(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			void *buf, uint16_t len, uint16_t offset);

//Callback of bluetooth write
static ssize_t write_otown(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			 const void *buf, uint16_t len, uint16_t offset,
			 uint8_t flags);

static void vnd_ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value); //Client Characterictics Configuration

static void connected(struct bt_conn *conn, uint8_t err);

static void disconnected(struct bt_conn *conn, uint8_t reason);

static void bt_ready(void);


#ifdef __cplusplus
}
#endif
