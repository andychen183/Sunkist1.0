// MESSAGE VEHICLE_REF_S PACKING

#define MAVLINK_MSG_ID_VEHICLE_REF_S 150

typedef struct __mavlink_vehicle_ref_s_t
{
 float x_ref; /*< x position ref in NED frame*/
 float y_ref; /*< y position ref in NED frame*/
 float z_ref; /*< z position ref in NED frame*/
 float vx_ref; /*< x vel ref in NED frame*/
 float vy_ref; /*< y vel ref in NED frame*/
 float vz_ref; /*< z vel ref in NED frame*/
 float accx_ref; /*< x acc ref in NED frame*/
 float accy_ref; /*< y acc ref in NED frame*/
 float accz_ref; /*< z acc ref in NED frame*/
 float yaw_ref; /*< yaw position ref in NED frame*/
 float yaw_speed_ref; /*< yaw speed ref in NED frame*/
 float servo1; /*< servo value 1 to pixhawk*/
 float servo2; /*< servo value 2 to pixhawk*/
 float servo3; /*< servo value 3 to pixhawk*/
 float servo4; /*< servo value 4 to pixhawk*/
 uint8_t cmd1; /*< cmd to pixhawk*/
 uint8_t cmd2; /*< cmd to pixhawk*/
 uint8_t cmd3; /*< cmd to pixhawk*/
} mavlink_vehicle_ref_s_t;

#define MAVLINK_MSG_ID_VEHICLE_REF_S_LEN 63
#define MAVLINK_MSG_ID_150_LEN 63

#define MAVLINK_MSG_ID_VEHICLE_REF_S_CRC 21
#define MAVLINK_MSG_ID_150_CRC 21



#define MAVLINK_MESSAGE_INFO_VEHICLE_REF_S { \
	"VEHICLE_REF_S", \
	18, \
	{  { "x_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vehicle_ref_s_t, x_ref) }, \
         { "y_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vehicle_ref_s_t, y_ref) }, \
         { "z_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vehicle_ref_s_t, z_ref) }, \
         { "vx_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vehicle_ref_s_t, vx_ref) }, \
         { "vy_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vehicle_ref_s_t, vy_ref) }, \
         { "vz_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vehicle_ref_s_t, vz_ref) }, \
         { "accx_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vehicle_ref_s_t, accx_ref) }, \
         { "accy_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vehicle_ref_s_t, accy_ref) }, \
         { "accz_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_vehicle_ref_s_t, accz_ref) }, \
         { "yaw_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_vehicle_ref_s_t, yaw_ref) }, \
         { "yaw_speed_ref", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_vehicle_ref_s_t, yaw_speed_ref) }, \
         { "servo1", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_vehicle_ref_s_t, servo1) }, \
         { "servo2", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_vehicle_ref_s_t, servo2) }, \
         { "servo3", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_vehicle_ref_s_t, servo3) }, \
         { "servo4", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_vehicle_ref_s_t, servo4) }, \
         { "cmd1", NULL, MAVLINK_TYPE_UINT8_T, 0, 60, offsetof(mavlink_vehicle_ref_s_t, cmd1) }, \
         { "cmd2", NULL, MAVLINK_TYPE_UINT8_T, 0, 61, offsetof(mavlink_vehicle_ref_s_t, cmd2) }, \
         { "cmd3", NULL, MAVLINK_TYPE_UINT8_T, 0, 62, offsetof(mavlink_vehicle_ref_s_t, cmd3) }, \
         } \
}


/**
 * @brief Pack a vehicle_ref_s message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x_ref x position ref in NED frame
 * @param y_ref y position ref in NED frame
 * @param z_ref z position ref in NED frame
 * @param vx_ref x vel ref in NED frame
 * @param vy_ref y vel ref in NED frame
 * @param vz_ref z vel ref in NED frame
 * @param accx_ref x acc ref in NED frame
 * @param accy_ref y acc ref in NED frame
 * @param accz_ref z acc ref in NED frame
 * @param yaw_ref yaw position ref in NED frame
 * @param yaw_speed_ref yaw speed ref in NED frame
 * @param cmd1 cmd to pixhawk
 * @param cmd2 cmd to pixhawk
 * @param cmd3 cmd to pixhawk
 * @param servo1 servo value 1 to pixhawk
 * @param servo2 servo value 2 to pixhawk
 * @param servo3 servo value 3 to pixhawk
 * @param servo4 servo value 4 to pixhawk
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_ref_s_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float x_ref, float y_ref, float z_ref, float vx_ref, float vy_ref, float vz_ref, float accx_ref, float accy_ref, float accz_ref, float yaw_ref, float yaw_speed_ref, uint8_t cmd1, uint8_t cmd2, uint8_t cmd3, float servo1, float servo2, float servo3, float servo4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VEHICLE_REF_S_LEN];
	_mav_put_float(buf, 0, x_ref);
	_mav_put_float(buf, 4, y_ref);
	_mav_put_float(buf, 8, z_ref);
	_mav_put_float(buf, 12, vx_ref);
	_mav_put_float(buf, 16, vy_ref);
	_mav_put_float(buf, 20, vz_ref);
	_mav_put_float(buf, 24, accx_ref);
	_mav_put_float(buf, 28, accy_ref);
	_mav_put_float(buf, 32, accz_ref);
	_mav_put_float(buf, 36, yaw_ref);
	_mav_put_float(buf, 40, yaw_speed_ref);
	_mav_put_float(buf, 44, servo1);
	_mav_put_float(buf, 48, servo2);
	_mav_put_float(buf, 52, servo3);
	_mav_put_float(buf, 56, servo4);
	_mav_put_uint8_t(buf, 60, cmd1);
	_mav_put_uint8_t(buf, 61, cmd2);
	_mav_put_uint8_t(buf, 62, cmd3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#else
	mavlink_vehicle_ref_s_t packet;
	packet.x_ref = x_ref;
	packet.y_ref = y_ref;
	packet.z_ref = z_ref;
	packet.vx_ref = vx_ref;
	packet.vy_ref = vy_ref;
	packet.vz_ref = vz_ref;
	packet.accx_ref = accx_ref;
	packet.accy_ref = accy_ref;
	packet.accz_ref = accz_ref;
	packet.yaw_ref = yaw_ref;
	packet.yaw_speed_ref = yaw_speed_ref;
	packet.servo1 = servo1;
	packet.servo2 = servo2;
	packet.servo3 = servo3;
	packet.servo4 = servo4;
	packet.cmd1 = cmd1;
	packet.cmd2 = cmd2;
	packet.cmd3 = cmd3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VEHICLE_REF_S;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN, MAVLINK_MSG_ID_VEHICLE_REF_S_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif
}

/**
 * @brief Pack a vehicle_ref_s message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x_ref x position ref in NED frame
 * @param y_ref y position ref in NED frame
 * @param z_ref z position ref in NED frame
 * @param vx_ref x vel ref in NED frame
 * @param vy_ref y vel ref in NED frame
 * @param vz_ref z vel ref in NED frame
 * @param accx_ref x acc ref in NED frame
 * @param accy_ref y acc ref in NED frame
 * @param accz_ref z acc ref in NED frame
 * @param yaw_ref yaw position ref in NED frame
 * @param yaw_speed_ref yaw speed ref in NED frame
 * @param cmd1 cmd to pixhawk
 * @param cmd2 cmd to pixhawk
 * @param cmd3 cmd to pixhawk
 * @param servo1 servo value 1 to pixhawk
 * @param servo2 servo value 2 to pixhawk
 * @param servo3 servo value 3 to pixhawk
 * @param servo4 servo value 4 to pixhawk
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_ref_s_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float x_ref,float y_ref,float z_ref,float vx_ref,float vy_ref,float vz_ref,float accx_ref,float accy_ref,float accz_ref,float yaw_ref,float yaw_speed_ref,uint8_t cmd1,uint8_t cmd2,uint8_t cmd3,float servo1,float servo2,float servo3,float servo4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VEHICLE_REF_S_LEN];
	_mav_put_float(buf, 0, x_ref);
	_mav_put_float(buf, 4, y_ref);
	_mav_put_float(buf, 8, z_ref);
	_mav_put_float(buf, 12, vx_ref);
	_mav_put_float(buf, 16, vy_ref);
	_mav_put_float(buf, 20, vz_ref);
	_mav_put_float(buf, 24, accx_ref);
	_mav_put_float(buf, 28, accy_ref);
	_mav_put_float(buf, 32, accz_ref);
	_mav_put_float(buf, 36, yaw_ref);
	_mav_put_float(buf, 40, yaw_speed_ref);
	_mav_put_float(buf, 44, servo1);
	_mav_put_float(buf, 48, servo2);
	_mav_put_float(buf, 52, servo3);
	_mav_put_float(buf, 56, servo4);
	_mav_put_uint8_t(buf, 60, cmd1);
	_mav_put_uint8_t(buf, 61, cmd2);
	_mav_put_uint8_t(buf, 62, cmd3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#else
	mavlink_vehicle_ref_s_t packet;
	packet.x_ref = x_ref;
	packet.y_ref = y_ref;
	packet.z_ref = z_ref;
	packet.vx_ref = vx_ref;
	packet.vy_ref = vy_ref;
	packet.vz_ref = vz_ref;
	packet.accx_ref = accx_ref;
	packet.accy_ref = accy_ref;
	packet.accz_ref = accz_ref;
	packet.yaw_ref = yaw_ref;
	packet.yaw_speed_ref = yaw_speed_ref;
	packet.servo1 = servo1;
	packet.servo2 = servo2;
	packet.servo3 = servo3;
	packet.servo4 = servo4;
	packet.cmd1 = cmd1;
	packet.cmd2 = cmd2;
	packet.cmd3 = cmd3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VEHICLE_REF_S;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN, MAVLINK_MSG_ID_VEHICLE_REF_S_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif
}

/**
 * @brief Encode a vehicle_ref_s struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_ref_s C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_ref_s_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vehicle_ref_s_t* vehicle_ref_s)
{
	return mavlink_msg_vehicle_ref_s_pack(system_id, component_id, msg, vehicle_ref_s->x_ref, vehicle_ref_s->y_ref, vehicle_ref_s->z_ref, vehicle_ref_s->vx_ref, vehicle_ref_s->vy_ref, vehicle_ref_s->vz_ref, vehicle_ref_s->accx_ref, vehicle_ref_s->accy_ref, vehicle_ref_s->accz_ref, vehicle_ref_s->yaw_ref, vehicle_ref_s->yaw_speed_ref, vehicle_ref_s->cmd1, vehicle_ref_s->cmd2, vehicle_ref_s->cmd3, vehicle_ref_s->servo1, vehicle_ref_s->servo2, vehicle_ref_s->servo3, vehicle_ref_s->servo4);
}

/**
 * @brief Encode a vehicle_ref_s struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_ref_s C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_ref_s_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vehicle_ref_s_t* vehicle_ref_s)
{
	return mavlink_msg_vehicle_ref_s_pack_chan(system_id, component_id, chan, msg, vehicle_ref_s->x_ref, vehicle_ref_s->y_ref, vehicle_ref_s->z_ref, vehicle_ref_s->vx_ref, vehicle_ref_s->vy_ref, vehicle_ref_s->vz_ref, vehicle_ref_s->accx_ref, vehicle_ref_s->accy_ref, vehicle_ref_s->accz_ref, vehicle_ref_s->yaw_ref, vehicle_ref_s->yaw_speed_ref, vehicle_ref_s->cmd1, vehicle_ref_s->cmd2, vehicle_ref_s->cmd3, vehicle_ref_s->servo1, vehicle_ref_s->servo2, vehicle_ref_s->servo3, vehicle_ref_s->servo4);
}

/**
 * @brief Send a vehicle_ref_s message
 * @param chan MAVLink channel to send the message
 *
 * @param x_ref x position ref in NED frame
 * @param y_ref y position ref in NED frame
 * @param z_ref z position ref in NED frame
 * @param vx_ref x vel ref in NED frame
 * @param vy_ref y vel ref in NED frame
 * @param vz_ref z vel ref in NED frame
 * @param accx_ref x acc ref in NED frame
 * @param accy_ref y acc ref in NED frame
 * @param accz_ref z acc ref in NED frame
 * @param yaw_ref yaw position ref in NED frame
 * @param yaw_speed_ref yaw speed ref in NED frame
 * @param cmd1 cmd to pixhawk
 * @param cmd2 cmd to pixhawk
 * @param cmd3 cmd to pixhawk
 * @param servo1 servo value 1 to pixhawk
 * @param servo2 servo value 2 to pixhawk
 * @param servo3 servo value 3 to pixhawk
 * @param servo4 servo value 4 to pixhawk
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vehicle_ref_s_send(mavlink_channel_t chan, float x_ref, float y_ref, float z_ref, float vx_ref, float vy_ref, float vz_ref, float accx_ref, float accy_ref, float accz_ref, float yaw_ref, float yaw_speed_ref, uint8_t cmd1, uint8_t cmd2, uint8_t cmd3, float servo1, float servo2, float servo3, float servo4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VEHICLE_REF_S_LEN];
	_mav_put_float(buf, 0, x_ref);
	_mav_put_float(buf, 4, y_ref);
	_mav_put_float(buf, 8, z_ref);
	_mav_put_float(buf, 12, vx_ref);
	_mav_put_float(buf, 16, vy_ref);
	_mav_put_float(buf, 20, vz_ref);
	_mav_put_float(buf, 24, accx_ref);
	_mav_put_float(buf, 28, accy_ref);
	_mav_put_float(buf, 32, accz_ref);
	_mav_put_float(buf, 36, yaw_ref);
	_mav_put_float(buf, 40, yaw_speed_ref);
	_mav_put_float(buf, 44, servo1);
	_mav_put_float(buf, 48, servo2);
	_mav_put_float(buf, 52, servo3);
	_mav_put_float(buf, 56, servo4);
	_mav_put_uint8_t(buf, 60, cmd1);
	_mav_put_uint8_t(buf, 61, cmd2);
	_mav_put_uint8_t(buf, 62, cmd3);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_REF_S, buf, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN, MAVLINK_MSG_ID_VEHICLE_REF_S_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_REF_S, buf, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif
#else
	mavlink_vehicle_ref_s_t packet;
	packet.x_ref = x_ref;
	packet.y_ref = y_ref;
	packet.z_ref = z_ref;
	packet.vx_ref = vx_ref;
	packet.vy_ref = vy_ref;
	packet.vz_ref = vz_ref;
	packet.accx_ref = accx_ref;
	packet.accy_ref = accy_ref;
	packet.accz_ref = accz_ref;
	packet.yaw_ref = yaw_ref;
	packet.yaw_speed_ref = yaw_speed_ref;
	packet.servo1 = servo1;
	packet.servo2 = servo2;
	packet.servo3 = servo3;
	packet.servo4 = servo4;
	packet.cmd1 = cmd1;
	packet.cmd2 = cmd2;
	packet.cmd3 = cmd3;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_REF_S, (const char *)&packet, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN, MAVLINK_MSG_ID_VEHICLE_REF_S_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_REF_S, (const char *)&packet, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_VEHICLE_REF_S_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vehicle_ref_s_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float x_ref, float y_ref, float z_ref, float vx_ref, float vy_ref, float vz_ref, float accx_ref, float accy_ref, float accz_ref, float yaw_ref, float yaw_speed_ref, uint8_t cmd1, uint8_t cmd2, uint8_t cmd3, float servo1, float servo2, float servo3, float servo4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, x_ref);
	_mav_put_float(buf, 4, y_ref);
	_mav_put_float(buf, 8, z_ref);
	_mav_put_float(buf, 12, vx_ref);
	_mav_put_float(buf, 16, vy_ref);
	_mav_put_float(buf, 20, vz_ref);
	_mav_put_float(buf, 24, accx_ref);
	_mav_put_float(buf, 28, accy_ref);
	_mav_put_float(buf, 32, accz_ref);
	_mav_put_float(buf, 36, yaw_ref);
	_mav_put_float(buf, 40, yaw_speed_ref);
	_mav_put_float(buf, 44, servo1);
	_mav_put_float(buf, 48, servo2);
	_mav_put_float(buf, 52, servo3);
	_mav_put_float(buf, 56, servo4);
	_mav_put_uint8_t(buf, 60, cmd1);
	_mav_put_uint8_t(buf, 61, cmd2);
	_mav_put_uint8_t(buf, 62, cmd3);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_REF_S, buf, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN, MAVLINK_MSG_ID_VEHICLE_REF_S_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_REF_S, buf, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif
#else
	mavlink_vehicle_ref_s_t *packet = (mavlink_vehicle_ref_s_t *)msgbuf;
	packet->x_ref = x_ref;
	packet->y_ref = y_ref;
	packet->z_ref = z_ref;
	packet->vx_ref = vx_ref;
	packet->vy_ref = vy_ref;
	packet->vz_ref = vz_ref;
	packet->accx_ref = accx_ref;
	packet->accy_ref = accy_ref;
	packet->accz_ref = accz_ref;
	packet->yaw_ref = yaw_ref;
	packet->yaw_speed_ref = yaw_speed_ref;
	packet->servo1 = servo1;
	packet->servo2 = servo2;
	packet->servo3 = servo3;
	packet->servo4 = servo4;
	packet->cmd1 = cmd1;
	packet->cmd2 = cmd2;
	packet->cmd3 = cmd3;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_REF_S, (const char *)packet, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN, MAVLINK_MSG_ID_VEHICLE_REF_S_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_REF_S, (const char *)packet, MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE VEHICLE_REF_S UNPACKING


/**
 * @brief Get field x_ref from vehicle_ref_s message
 *
 * @return x position ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_x_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y_ref from vehicle_ref_s message
 *
 * @return y position ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_y_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field z_ref from vehicle_ref_s message
 *
 * @return z position ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_z_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vx_ref from vehicle_ref_s message
 *
 * @return x vel ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_vx_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field vy_ref from vehicle_ref_s message
 *
 * @return y vel ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_vy_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field vz_ref from vehicle_ref_s message
 *
 * @return z vel ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_vz_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field accx_ref from vehicle_ref_s message
 *
 * @return x acc ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_accx_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field accy_ref from vehicle_ref_s message
 *
 * @return y acc ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_accy_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field accz_ref from vehicle_ref_s message
 *
 * @return z acc ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_accz_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field yaw_ref from vehicle_ref_s message
 *
 * @return yaw position ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_yaw_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field yaw_speed_ref from vehicle_ref_s message
 *
 * @return yaw speed ref in NED frame
 */
static inline float mavlink_msg_vehicle_ref_s_get_yaw_speed_ref(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field cmd1 from vehicle_ref_s message
 *
 * @return cmd to pixhawk
 */
static inline uint8_t mavlink_msg_vehicle_ref_s_get_cmd1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  60);
}

/**
 * @brief Get field cmd2 from vehicle_ref_s message
 *
 * @return cmd to pixhawk
 */
static inline uint8_t mavlink_msg_vehicle_ref_s_get_cmd2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  61);
}

/**
 * @brief Get field cmd3 from vehicle_ref_s message
 *
 * @return cmd to pixhawk
 */
static inline uint8_t mavlink_msg_vehicle_ref_s_get_cmd3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  62);
}

/**
 * @brief Get field servo1 from vehicle_ref_s message
 *
 * @return servo value 1 to pixhawk
 */
static inline float mavlink_msg_vehicle_ref_s_get_servo1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field servo2 from vehicle_ref_s message
 *
 * @return servo value 2 to pixhawk
 */
static inline float mavlink_msg_vehicle_ref_s_get_servo2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field servo3 from vehicle_ref_s message
 *
 * @return servo value 3 to pixhawk
 */
static inline float mavlink_msg_vehicle_ref_s_get_servo3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field servo4 from vehicle_ref_s message
 *
 * @return servo value 4 to pixhawk
 */
static inline float mavlink_msg_vehicle_ref_s_get_servo4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Decode a vehicle_ref_s message into a struct
 *
 * @param msg The message to decode
 * @param vehicle_ref_s C-struct to decode the message contents into
 */
static inline void mavlink_msg_vehicle_ref_s_decode(const mavlink_message_t* msg, mavlink_vehicle_ref_s_t* vehicle_ref_s)
{
#if MAVLINK_NEED_BYTE_SWAP
	vehicle_ref_s->x_ref = mavlink_msg_vehicle_ref_s_get_x_ref(msg);
	vehicle_ref_s->y_ref = mavlink_msg_vehicle_ref_s_get_y_ref(msg);
	vehicle_ref_s->z_ref = mavlink_msg_vehicle_ref_s_get_z_ref(msg);
	vehicle_ref_s->vx_ref = mavlink_msg_vehicle_ref_s_get_vx_ref(msg);
	vehicle_ref_s->vy_ref = mavlink_msg_vehicle_ref_s_get_vy_ref(msg);
	vehicle_ref_s->vz_ref = mavlink_msg_vehicle_ref_s_get_vz_ref(msg);
	vehicle_ref_s->accx_ref = mavlink_msg_vehicle_ref_s_get_accx_ref(msg);
	vehicle_ref_s->accy_ref = mavlink_msg_vehicle_ref_s_get_accy_ref(msg);
	vehicle_ref_s->accz_ref = mavlink_msg_vehicle_ref_s_get_accz_ref(msg);
	vehicle_ref_s->yaw_ref = mavlink_msg_vehicle_ref_s_get_yaw_ref(msg);
	vehicle_ref_s->yaw_speed_ref = mavlink_msg_vehicle_ref_s_get_yaw_speed_ref(msg);
	vehicle_ref_s->servo1 = mavlink_msg_vehicle_ref_s_get_servo1(msg);
	vehicle_ref_s->servo2 = mavlink_msg_vehicle_ref_s_get_servo2(msg);
	vehicle_ref_s->servo3 = mavlink_msg_vehicle_ref_s_get_servo3(msg);
	vehicle_ref_s->servo4 = mavlink_msg_vehicle_ref_s_get_servo4(msg);
	vehicle_ref_s->cmd1 = mavlink_msg_vehicle_ref_s_get_cmd1(msg);
	vehicle_ref_s->cmd2 = mavlink_msg_vehicle_ref_s_get_cmd2(msg);
	vehicle_ref_s->cmd3 = mavlink_msg_vehicle_ref_s_get_cmd3(msg);
#else
	memcpy(vehicle_ref_s, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_VEHICLE_REF_S_LEN);
#endif
}
