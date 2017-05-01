// MESSAGE VEHICLE_MEA_S PACKING

#define MAVLINK_MSG_ID_VEHICLE_MEA_S 152

typedef struct __mavlink_vehicle_mea_s_t
{
 float x; /*< x in NED frame*/
 float y; /*< y in NED frame*/
 float z; /*< z in NED frame*/
 float vx; /*< vx in NED frame*/
 float vy; /*< vy in NED frame*/
 float vz; /*< vz in NED frame*/
 float roll; /*< roll in NED frame*/
 float pitch; /*< pitch in NED frame*/
 float yaw; /*< yaw in NED frame*/
 uint8_t xy_valid; /*< judge whether xy valid*/
 uint8_t z_valid; /*< judge whether z valid*/
 uint8_t v_xy_valid; /*< juydge velocity in xy valid*/
 uint8_t v_z_valid; /*< judge velocity in z valid*/
 uint8_t ned_valid; /*< judge ned direction valid*/
 uint8_t yaw_valid; /*< judge yaw or the other direction valid*/
 uint8_t cmd1; /*< cmd to pixhawk*/
 uint8_t cmd2; /*< cmd to pixhawk*/
 uint8_t cmd3; /*< cmd to pixhawk*/
} mavlink_vehicle_mea_s_t;

#define MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN 45
#define MAVLINK_MSG_ID_152_LEN 45

#define MAVLINK_MSG_ID_VEHICLE_MEA_S_CRC 60
#define MAVLINK_MSG_ID_152_CRC 60



#define MAVLINK_MESSAGE_INFO_VEHICLE_MEA_S { \
	"VEHICLE_MEA_S", \
	18, \
	{  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vehicle_mea_s_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vehicle_mea_s_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vehicle_mea_s_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vehicle_mea_s_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vehicle_mea_s_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vehicle_mea_s_t, vz) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vehicle_mea_s_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vehicle_mea_s_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_vehicle_mea_s_t, yaw) }, \
         { "xy_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_vehicle_mea_s_t, xy_valid) }, \
         { "z_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_vehicle_mea_s_t, z_valid) }, \
         { "v_xy_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_vehicle_mea_s_t, v_xy_valid) }, \
         { "v_z_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_vehicle_mea_s_t, v_z_valid) }, \
         { "ned_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_vehicle_mea_s_t, ned_valid) }, \
         { "yaw_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_vehicle_mea_s_t, yaw_valid) }, \
         { "cmd1", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_vehicle_mea_s_t, cmd1) }, \
         { "cmd2", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_vehicle_mea_s_t, cmd2) }, \
         { "cmd3", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_vehicle_mea_s_t, cmd3) }, \
         } \
}


/**
 * @brief Pack a vehicle_mea_s message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param xy_valid judge whether xy valid
 * @param z_valid judge whether z valid
 * @param v_xy_valid juydge velocity in xy valid
 * @param v_z_valid judge velocity in z valid
 * @param ned_valid judge ned direction valid
 * @param yaw_valid judge yaw or the other direction valid
 * @param x x in NED frame
 * @param y y in NED frame
 * @param z z in NED frame
 * @param vx vx in NED frame
 * @param vy vy in NED frame
 * @param vz vz in NED frame
 * @param roll roll in NED frame
 * @param pitch pitch in NED frame
 * @param yaw yaw in NED frame
 * @param cmd1 cmd to pixhawk
 * @param cmd2 cmd to pixhawk
 * @param cmd3 cmd to pixhawk
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_mea_s_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t xy_valid, uint8_t z_valid, uint8_t v_xy_valid, uint8_t v_z_valid, uint8_t ned_valid, uint8_t yaw_valid, float x, float y, float z, float vx, float vy, float vz, float roll, float pitch, float yaw, uint8_t cmd1, uint8_t cmd2, uint8_t cmd3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN];
	_mav_put_float(buf, 0, x);
	_mav_put_float(buf, 4, y);
	_mav_put_float(buf, 8, z);
	_mav_put_float(buf, 12, vx);
	_mav_put_float(buf, 16, vy);
	_mav_put_float(buf, 20, vz);
	_mav_put_float(buf, 24, roll);
	_mav_put_float(buf, 28, pitch);
	_mav_put_float(buf, 32, yaw);
	_mav_put_uint8_t(buf, 36, xy_valid);
	_mav_put_uint8_t(buf, 37, z_valid);
	_mav_put_uint8_t(buf, 38, v_xy_valid);
	_mav_put_uint8_t(buf, 39, v_z_valid);
	_mav_put_uint8_t(buf, 40, ned_valid);
	_mav_put_uint8_t(buf, 41, yaw_valid);
	_mav_put_uint8_t(buf, 42, cmd1);
	_mav_put_uint8_t(buf, 43, cmd2);
	_mav_put_uint8_t(buf, 44, cmd3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#else
	mavlink_vehicle_mea_s_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.xy_valid = xy_valid;
	packet.z_valid = z_valid;
	packet.v_xy_valid = v_xy_valid;
	packet.v_z_valid = v_z_valid;
	packet.ned_valid = ned_valid;
	packet.yaw_valid = yaw_valid;
	packet.cmd1 = cmd1;
	packet.cmd2 = cmd2;
	packet.cmd3 = cmd3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VEHICLE_MEA_S;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN, MAVLINK_MSG_ID_VEHICLE_MEA_S_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif
}

/**
 * @brief Pack a vehicle_mea_s message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param xy_valid judge whether xy valid
 * @param z_valid judge whether z valid
 * @param v_xy_valid juydge velocity in xy valid
 * @param v_z_valid judge velocity in z valid
 * @param ned_valid judge ned direction valid
 * @param yaw_valid judge yaw or the other direction valid
 * @param x x in NED frame
 * @param y y in NED frame
 * @param z z in NED frame
 * @param vx vx in NED frame
 * @param vy vy in NED frame
 * @param vz vz in NED frame
 * @param roll roll in NED frame
 * @param pitch pitch in NED frame
 * @param yaw yaw in NED frame
 * @param cmd1 cmd to pixhawk
 * @param cmd2 cmd to pixhawk
 * @param cmd3 cmd to pixhawk
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_mea_s_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t xy_valid,uint8_t z_valid,uint8_t v_xy_valid,uint8_t v_z_valid,uint8_t ned_valid,uint8_t yaw_valid,float x,float y,float z,float vx,float vy,float vz,float roll,float pitch,float yaw,uint8_t cmd1,uint8_t cmd2,uint8_t cmd3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN];
	_mav_put_float(buf, 0, x);
	_mav_put_float(buf, 4, y);
	_mav_put_float(buf, 8, z);
	_mav_put_float(buf, 12, vx);
	_mav_put_float(buf, 16, vy);
	_mav_put_float(buf, 20, vz);
	_mav_put_float(buf, 24, roll);
	_mav_put_float(buf, 28, pitch);
	_mav_put_float(buf, 32, yaw);
	_mav_put_uint8_t(buf, 36, xy_valid);
	_mav_put_uint8_t(buf, 37, z_valid);
	_mav_put_uint8_t(buf, 38, v_xy_valid);
	_mav_put_uint8_t(buf, 39, v_z_valid);
	_mav_put_uint8_t(buf, 40, ned_valid);
	_mav_put_uint8_t(buf, 41, yaw_valid);
	_mav_put_uint8_t(buf, 42, cmd1);
	_mav_put_uint8_t(buf, 43, cmd2);
	_mav_put_uint8_t(buf, 44, cmd3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#else
	mavlink_vehicle_mea_s_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.xy_valid = xy_valid;
	packet.z_valid = z_valid;
	packet.v_xy_valid = v_xy_valid;
	packet.v_z_valid = v_z_valid;
	packet.ned_valid = ned_valid;
	packet.yaw_valid = yaw_valid;
	packet.cmd1 = cmd1;
	packet.cmd2 = cmd2;
	packet.cmd3 = cmd3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VEHICLE_MEA_S;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN, MAVLINK_MSG_ID_VEHICLE_MEA_S_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif
}

/**
 * @brief Encode a vehicle_mea_s struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_mea_s C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_mea_s_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vehicle_mea_s_t* vehicle_mea_s)
{
	return mavlink_msg_vehicle_mea_s_pack(system_id, component_id, msg, vehicle_mea_s->xy_valid, vehicle_mea_s->z_valid, vehicle_mea_s->v_xy_valid, vehicle_mea_s->v_z_valid, vehicle_mea_s->ned_valid, vehicle_mea_s->yaw_valid, vehicle_mea_s->x, vehicle_mea_s->y, vehicle_mea_s->z, vehicle_mea_s->vx, vehicle_mea_s->vy, vehicle_mea_s->vz, vehicle_mea_s->roll, vehicle_mea_s->pitch, vehicle_mea_s->yaw, vehicle_mea_s->cmd1, vehicle_mea_s->cmd2, vehicle_mea_s->cmd3);
}

/**
 * @brief Encode a vehicle_mea_s struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_mea_s C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_mea_s_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vehicle_mea_s_t* vehicle_mea_s)
{
	return mavlink_msg_vehicle_mea_s_pack_chan(system_id, component_id, chan, msg, vehicle_mea_s->xy_valid, vehicle_mea_s->z_valid, vehicle_mea_s->v_xy_valid, vehicle_mea_s->v_z_valid, vehicle_mea_s->ned_valid, vehicle_mea_s->yaw_valid, vehicle_mea_s->x, vehicle_mea_s->y, vehicle_mea_s->z, vehicle_mea_s->vx, vehicle_mea_s->vy, vehicle_mea_s->vz, vehicle_mea_s->roll, vehicle_mea_s->pitch, vehicle_mea_s->yaw, vehicle_mea_s->cmd1, vehicle_mea_s->cmd2, vehicle_mea_s->cmd3);
}

/**
 * @brief Send a vehicle_mea_s message
 * @param chan MAVLink channel to send the message
 *
 * @param xy_valid judge whether xy valid
 * @param z_valid judge whether z valid
 * @param v_xy_valid juydge velocity in xy valid
 * @param v_z_valid judge velocity in z valid
 * @param ned_valid judge ned direction valid
 * @param yaw_valid judge yaw or the other direction valid
 * @param x x in NED frame
 * @param y y in NED frame
 * @param z z in NED frame
 * @param vx vx in NED frame
 * @param vy vy in NED frame
 * @param vz vz in NED frame
 * @param roll roll in NED frame
 * @param pitch pitch in NED frame
 * @param yaw yaw in NED frame
 * @param cmd1 cmd to pixhawk
 * @param cmd2 cmd to pixhawk
 * @param cmd3 cmd to pixhawk
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vehicle_mea_s_send(mavlink_channel_t chan, uint8_t xy_valid, uint8_t z_valid, uint8_t v_xy_valid, uint8_t v_z_valid, uint8_t ned_valid, uint8_t yaw_valid, float x, float y, float z, float vx, float vy, float vz, float roll, float pitch, float yaw, uint8_t cmd1, uint8_t cmd2, uint8_t cmd3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN];
	_mav_put_float(buf, 0, x);
	_mav_put_float(buf, 4, y);
	_mav_put_float(buf, 8, z);
	_mav_put_float(buf, 12, vx);
	_mav_put_float(buf, 16, vy);
	_mav_put_float(buf, 20, vz);
	_mav_put_float(buf, 24, roll);
	_mav_put_float(buf, 28, pitch);
	_mav_put_float(buf, 32, yaw);
	_mav_put_uint8_t(buf, 36, xy_valid);
	_mav_put_uint8_t(buf, 37, z_valid);
	_mav_put_uint8_t(buf, 38, v_xy_valid);
	_mav_put_uint8_t(buf, 39, v_z_valid);
	_mav_put_uint8_t(buf, 40, ned_valid);
	_mav_put_uint8_t(buf, 41, yaw_valid);
	_mav_put_uint8_t(buf, 42, cmd1);
	_mav_put_uint8_t(buf, 43, cmd2);
	_mav_put_uint8_t(buf, 44, cmd3);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_MEA_S, buf, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN, MAVLINK_MSG_ID_VEHICLE_MEA_S_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_MEA_S, buf, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif
#else
	mavlink_vehicle_mea_s_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.xy_valid = xy_valid;
	packet.z_valid = z_valid;
	packet.v_xy_valid = v_xy_valid;
	packet.v_z_valid = v_z_valid;
	packet.ned_valid = ned_valid;
	packet.yaw_valid = yaw_valid;
	packet.cmd1 = cmd1;
	packet.cmd2 = cmd2;
	packet.cmd3 = cmd3;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_MEA_S, (const char *)&packet, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN, MAVLINK_MSG_ID_VEHICLE_MEA_S_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_MEA_S, (const char *)&packet, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vehicle_mea_s_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t xy_valid, uint8_t z_valid, uint8_t v_xy_valid, uint8_t v_z_valid, uint8_t ned_valid, uint8_t yaw_valid, float x, float y, float z, float vx, float vy, float vz, float roll, float pitch, float yaw, uint8_t cmd1, uint8_t cmd2, uint8_t cmd3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, x);
	_mav_put_float(buf, 4, y);
	_mav_put_float(buf, 8, z);
	_mav_put_float(buf, 12, vx);
	_mav_put_float(buf, 16, vy);
	_mav_put_float(buf, 20, vz);
	_mav_put_float(buf, 24, roll);
	_mav_put_float(buf, 28, pitch);
	_mav_put_float(buf, 32, yaw);
	_mav_put_uint8_t(buf, 36, xy_valid);
	_mav_put_uint8_t(buf, 37, z_valid);
	_mav_put_uint8_t(buf, 38, v_xy_valid);
	_mav_put_uint8_t(buf, 39, v_z_valid);
	_mav_put_uint8_t(buf, 40, ned_valid);
	_mav_put_uint8_t(buf, 41, yaw_valid);
	_mav_put_uint8_t(buf, 42, cmd1);
	_mav_put_uint8_t(buf, 43, cmd2);
	_mav_put_uint8_t(buf, 44, cmd3);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_MEA_S, buf, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN, MAVLINK_MSG_ID_VEHICLE_MEA_S_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_MEA_S, buf, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif
#else
	mavlink_vehicle_mea_s_t *packet = (mavlink_vehicle_mea_s_t *)msgbuf;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->vx = vx;
	packet->vy = vy;
	packet->vz = vz;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->xy_valid = xy_valid;
	packet->z_valid = z_valid;
	packet->v_xy_valid = v_xy_valid;
	packet->v_z_valid = v_z_valid;
	packet->ned_valid = ned_valid;
	packet->yaw_valid = yaw_valid;
	packet->cmd1 = cmd1;
	packet->cmd2 = cmd2;
	packet->cmd3 = cmd3;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_MEA_S, (const char *)packet, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN, MAVLINK_MSG_ID_VEHICLE_MEA_S_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_MEA_S, (const char *)packet, MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE VEHICLE_MEA_S UNPACKING


/**
 * @brief Get field xy_valid from vehicle_mea_s message
 *
 * @return judge whether xy valid
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_xy_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field z_valid from vehicle_mea_s message
 *
 * @return judge whether z valid
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_z_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field v_xy_valid from vehicle_mea_s message
 *
 * @return juydge velocity in xy valid
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_v_xy_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  38);
}

/**
 * @brief Get field v_z_valid from vehicle_mea_s message
 *
 * @return judge velocity in z valid
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_v_z_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  39);
}

/**
 * @brief Get field ned_valid from vehicle_mea_s message
 *
 * @return judge ned direction valid
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_ned_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field yaw_valid from vehicle_mea_s message
 *
 * @return judge yaw or the other direction valid
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_yaw_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  41);
}

/**
 * @brief Get field x from vehicle_mea_s message
 *
 * @return x in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from vehicle_mea_s message
 *
 * @return y in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field z from vehicle_mea_s message
 *
 * @return z in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vx from vehicle_mea_s message
 *
 * @return vx in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_vx(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field vy from vehicle_mea_s message
 *
 * @return vy in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_vy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field vz from vehicle_mea_s message
 *
 * @return vz in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_vz(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field roll from vehicle_mea_s message
 *
 * @return roll in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field pitch from vehicle_mea_s message
 *
 * @return pitch in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field yaw from vehicle_mea_s message
 *
 * @return yaw in NED frame
 */
static inline float mavlink_msg_vehicle_mea_s_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field cmd1 from vehicle_mea_s message
 *
 * @return cmd to pixhawk
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_cmd1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field cmd2 from vehicle_mea_s message
 *
 * @return cmd to pixhawk
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_cmd2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Get field cmd3 from vehicle_mea_s message
 *
 * @return cmd to pixhawk
 */
static inline uint8_t mavlink_msg_vehicle_mea_s_get_cmd3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Decode a vehicle_mea_s message into a struct
 *
 * @param msg The message to decode
 * @param vehicle_mea_s C-struct to decode the message contents into
 */
static inline void mavlink_msg_vehicle_mea_s_decode(const mavlink_message_t* msg, mavlink_vehicle_mea_s_t* vehicle_mea_s)
{
#if MAVLINK_NEED_BYTE_SWAP
	vehicle_mea_s->x = mavlink_msg_vehicle_mea_s_get_x(msg);
	vehicle_mea_s->y = mavlink_msg_vehicle_mea_s_get_y(msg);
	vehicle_mea_s->z = mavlink_msg_vehicle_mea_s_get_z(msg);
	vehicle_mea_s->vx = mavlink_msg_vehicle_mea_s_get_vx(msg);
	vehicle_mea_s->vy = mavlink_msg_vehicle_mea_s_get_vy(msg);
	vehicle_mea_s->vz = mavlink_msg_vehicle_mea_s_get_vz(msg);
	vehicle_mea_s->roll = mavlink_msg_vehicle_mea_s_get_roll(msg);
	vehicle_mea_s->pitch = mavlink_msg_vehicle_mea_s_get_pitch(msg);
	vehicle_mea_s->yaw = mavlink_msg_vehicle_mea_s_get_yaw(msg);
	vehicle_mea_s->xy_valid = mavlink_msg_vehicle_mea_s_get_xy_valid(msg);
	vehicle_mea_s->z_valid = mavlink_msg_vehicle_mea_s_get_z_valid(msg);
	vehicle_mea_s->v_xy_valid = mavlink_msg_vehicle_mea_s_get_v_xy_valid(msg);
	vehicle_mea_s->v_z_valid = mavlink_msg_vehicle_mea_s_get_v_z_valid(msg);
	vehicle_mea_s->ned_valid = mavlink_msg_vehicle_mea_s_get_ned_valid(msg);
	vehicle_mea_s->yaw_valid = mavlink_msg_vehicle_mea_s_get_yaw_valid(msg);
	vehicle_mea_s->cmd1 = mavlink_msg_vehicle_mea_s_get_cmd1(msg);
	vehicle_mea_s->cmd2 = mavlink_msg_vehicle_mea_s_get_cmd2(msg);
	vehicle_mea_s->cmd3 = mavlink_msg_vehicle_mea_s_get_cmd3(msg);
#else
	memcpy(vehicle_mea_s, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_VEHICLE_MEA_S_LEN);
#endif
}
