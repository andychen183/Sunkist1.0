// MESSAGE SERVO_VALUE PACKING

#define MAVLINK_MSG_ID_SERVO_VALUE 153

typedef struct __mavlink_servo_value_t
{
 float servo1; /*< servo1 in the aux1 output*/
 float servo2; /*< servo2 in the aux1 output*/
 float servo3; /*< servo3 in the aux1 output*/
 float servo4; /*< servo4 in the aux1 output*/
 float servo5; /*< servo4 in the aux1 output*/
 float servo6; /*< servo4 in the aux1 output*/
} mavlink_servo_value_t;

#define MAVLINK_MSG_ID_SERVO_VALUE_LEN 24
#define MAVLINK_MSG_ID_153_LEN 24

#define MAVLINK_MSG_ID_SERVO_VALUE_CRC 97
#define MAVLINK_MSG_ID_153_CRC 97



#define MAVLINK_MESSAGE_INFO_SERVO_VALUE { \
	"SERVO_VALUE", \
	6, \
	{  { "servo1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_servo_value_t, servo1) }, \
         { "servo2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_servo_value_t, servo2) }, \
         { "servo3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_servo_value_t, servo3) }, \
         { "servo4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_servo_value_t, servo4) }, \
         { "servo5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_servo_value_t, servo5) }, \
         { "servo6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_servo_value_t, servo6) }, \
         } \
}


/**
 * @brief Pack a servo_value message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param servo1 servo1 in the aux1 output
 * @param servo2 servo2 in the aux1 output
 * @param servo3 servo3 in the aux1 output
 * @param servo4 servo4 in the aux1 output
 * @param servo5 servo4 in the aux1 output
 * @param servo6 servo4 in the aux1 output
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_servo_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float servo1, float servo2, float servo3, float servo4, float servo5, float servo6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SERVO_VALUE_LEN];
	_mav_put_float(buf, 0, servo1);
	_mav_put_float(buf, 4, servo2);
	_mav_put_float(buf, 8, servo3);
	_mav_put_float(buf, 12, servo4);
	_mav_put_float(buf, 16, servo5);
	_mav_put_float(buf, 20, servo6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#else
	mavlink_servo_value_t packet;
	packet.servo1 = servo1;
	packet.servo2 = servo2;
	packet.servo3 = servo3;
	packet.servo4 = servo4;
	packet.servo5 = servo5;
	packet.servo6 = servo6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SERVO_VALUE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SERVO_VALUE_LEN, MAVLINK_MSG_ID_SERVO_VALUE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif
}

/**
 * @brief Pack a servo_value message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param servo1 servo1 in the aux1 output
 * @param servo2 servo2 in the aux1 output
 * @param servo3 servo3 in the aux1 output
 * @param servo4 servo4 in the aux1 output
 * @param servo5 servo4 in the aux1 output
 * @param servo6 servo4 in the aux1 output
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_servo_value_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float servo1,float servo2,float servo3,float servo4,float servo5,float servo6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SERVO_VALUE_LEN];
	_mav_put_float(buf, 0, servo1);
	_mav_put_float(buf, 4, servo2);
	_mav_put_float(buf, 8, servo3);
	_mav_put_float(buf, 12, servo4);
	_mav_put_float(buf, 16, servo5);
	_mav_put_float(buf, 20, servo6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#else
	mavlink_servo_value_t packet;
	packet.servo1 = servo1;
	packet.servo2 = servo2;
	packet.servo3 = servo3;
	packet.servo4 = servo4;
	packet.servo5 = servo5;
	packet.servo6 = servo6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SERVO_VALUE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SERVO_VALUE_LEN, MAVLINK_MSG_ID_SERVO_VALUE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif
}

/**
 * @brief Encode a servo_value struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param servo_value C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_servo_value_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_servo_value_t* servo_value)
{
	return mavlink_msg_servo_value_pack(system_id, component_id, msg, servo_value->servo1, servo_value->servo2, servo_value->servo3, servo_value->servo4, servo_value->servo5, servo_value->servo6);
}

/**
 * @brief Encode a servo_value struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param servo_value C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_servo_value_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_servo_value_t* servo_value)
{
	return mavlink_msg_servo_value_pack_chan(system_id, component_id, chan, msg, servo_value->servo1, servo_value->servo2, servo_value->servo3, servo_value->servo4, servo_value->servo5, servo_value->servo6);
}

/**
 * @brief Send a servo_value message
 * @param chan MAVLink channel to send the message
 *
 * @param servo1 servo1 in the aux1 output
 * @param servo2 servo2 in the aux1 output
 * @param servo3 servo3 in the aux1 output
 * @param servo4 servo4 in the aux1 output
 * @param servo5 servo4 in the aux1 output
 * @param servo6 servo4 in the aux1 output
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_servo_value_send(mavlink_channel_t chan, float servo1, float servo2, float servo3, float servo4, float servo5, float servo6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SERVO_VALUE_LEN];
	_mav_put_float(buf, 0, servo1);
	_mav_put_float(buf, 4, servo2);
	_mav_put_float(buf, 8, servo3);
	_mav_put_float(buf, 12, servo4);
	_mav_put_float(buf, 16, servo5);
	_mav_put_float(buf, 20, servo6);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_VALUE, buf, MAVLINK_MSG_ID_SERVO_VALUE_LEN, MAVLINK_MSG_ID_SERVO_VALUE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_VALUE, buf, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif
#else
	mavlink_servo_value_t packet;
	packet.servo1 = servo1;
	packet.servo2 = servo2;
	packet.servo3 = servo3;
	packet.servo4 = servo4;
	packet.servo5 = servo5;
	packet.servo6 = servo6;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_VALUE, (const char *)&packet, MAVLINK_MSG_ID_SERVO_VALUE_LEN, MAVLINK_MSG_ID_SERVO_VALUE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_VALUE, (const char *)&packet, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SERVO_VALUE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_servo_value_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float servo1, float servo2, float servo3, float servo4, float servo5, float servo6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, servo1);
	_mav_put_float(buf, 4, servo2);
	_mav_put_float(buf, 8, servo3);
	_mav_put_float(buf, 12, servo4);
	_mav_put_float(buf, 16, servo5);
	_mav_put_float(buf, 20, servo6);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_VALUE, buf, MAVLINK_MSG_ID_SERVO_VALUE_LEN, MAVLINK_MSG_ID_SERVO_VALUE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_VALUE, buf, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif
#else
	mavlink_servo_value_t *packet = (mavlink_servo_value_t *)msgbuf;
	packet->servo1 = servo1;
	packet->servo2 = servo2;
	packet->servo3 = servo3;
	packet->servo4 = servo4;
	packet->servo5 = servo5;
	packet->servo6 = servo6;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_VALUE, (const char *)packet, MAVLINK_MSG_ID_SERVO_VALUE_LEN, MAVLINK_MSG_ID_SERVO_VALUE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_VALUE, (const char *)packet, MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SERVO_VALUE UNPACKING


/**
 * @brief Get field servo1 from servo_value message
 *
 * @return servo1 in the aux1 output
 */
static inline float mavlink_msg_servo_value_get_servo1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field servo2 from servo_value message
 *
 * @return servo2 in the aux1 output
 */
static inline float mavlink_msg_servo_value_get_servo2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field servo3 from servo_value message
 *
 * @return servo3 in the aux1 output
 */
static inline float mavlink_msg_servo_value_get_servo3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field servo4 from servo_value message
 *
 * @return servo4 in the aux1 output
 */
static inline float mavlink_msg_servo_value_get_servo4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field servo5 from servo_value message
 *
 * @return servo4 in the aux1 output
 */
static inline float mavlink_msg_servo_value_get_servo5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field servo6 from servo_value message
 *
 * @return servo4 in the aux1 output
 */
static inline float mavlink_msg_servo_value_get_servo6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a servo_value message into a struct
 *
 * @param msg The message to decode
 * @param servo_value C-struct to decode the message contents into
 */
static inline void mavlink_msg_servo_value_decode(const mavlink_message_t* msg, mavlink_servo_value_t* servo_value)
{
#if MAVLINK_NEED_BYTE_SWAP
	servo_value->servo1 = mavlink_msg_servo_value_get_servo1(msg);
	servo_value->servo2 = mavlink_msg_servo_value_get_servo2(msg);
	servo_value->servo3 = mavlink_msg_servo_value_get_servo3(msg);
	servo_value->servo4 = mavlink_msg_servo_value_get_servo4(msg);
	servo_value->servo5 = mavlink_msg_servo_value_get_servo5(msg);
	servo_value->servo6 = mavlink_msg_servo_value_get_servo6(msg);
#else
	memcpy(servo_value, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SERVO_VALUE_LEN);
#endif
}
