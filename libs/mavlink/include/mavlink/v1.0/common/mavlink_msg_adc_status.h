// MESSAGE ADC_STATUS PACKING

#define MAVLINK_MSG_ID_ADC_STATUS 151

typedef struct __mavlink_adc_status_t
{
 uint8_t adc_port1; /*< adc status of the adc port1*/
 uint8_t adc_port2; /*< adc status of the adc port2*/
 uint8_t bucket_status; /*< bucket_status */
} mavlink_adc_status_t;

#define MAVLINK_MSG_ID_ADC_STATUS_LEN 3
#define MAVLINK_MSG_ID_151_LEN 3

#define MAVLINK_MSG_ID_ADC_STATUS_CRC 43
#define MAVLINK_MSG_ID_151_CRC 43



#define MAVLINK_MESSAGE_INFO_ADC_STATUS { \
	"ADC_STATUS", \
	3, \
	{  { "adc_port1", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_adc_status_t, adc_port1) }, \
         { "adc_port2", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_adc_status_t, adc_port2) }, \
         { "bucket_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_adc_status_t, bucket_status) }, \
         } \
}


/**
 * @brief Pack a adc_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param adc_port1 adc status of the adc port1
 * @param adc_port2 adc status of the adc port2
 * @param bucket_status bucket_status 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_adc_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t adc_port1, uint8_t adc_port2, uint8_t bucket_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_STATUS_LEN];
	_mav_put_uint8_t(buf, 0, adc_port1);
	_mav_put_uint8_t(buf, 1, adc_port2);
	_mav_put_uint8_t(buf, 2, bucket_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#else
	mavlink_adc_status_t packet;
	packet.adc_port1 = adc_port1;
	packet.adc_port2 = adc_port2;
	packet.bucket_status = bucket_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ADC_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ADC_STATUS_LEN, MAVLINK_MSG_ID_ADC_STATUS_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif
}

/**
 * @brief Pack a adc_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param adc_port1 adc status of the adc port1
 * @param adc_port2 adc status of the adc port2
 * @param bucket_status bucket_status 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_adc_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t adc_port1,uint8_t adc_port2,uint8_t bucket_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_STATUS_LEN];
	_mav_put_uint8_t(buf, 0, adc_port1);
	_mav_put_uint8_t(buf, 1, adc_port2);
	_mav_put_uint8_t(buf, 2, bucket_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#else
	mavlink_adc_status_t packet;
	packet.adc_port1 = adc_port1;
	packet.adc_port2 = adc_port2;
	packet.bucket_status = bucket_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ADC_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ADC_STATUS_LEN, MAVLINK_MSG_ID_ADC_STATUS_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif
}

/**
 * @brief Encode a adc_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param adc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_adc_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_adc_status_t* adc_status)
{
	return mavlink_msg_adc_status_pack(system_id, component_id, msg, adc_status->adc_port1, adc_status->adc_port2, adc_status->bucket_status);
}

/**
 * @brief Encode a adc_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param adc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_adc_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_adc_status_t* adc_status)
{
	return mavlink_msg_adc_status_pack_chan(system_id, component_id, chan, msg, adc_status->adc_port1, adc_status->adc_port2, adc_status->bucket_status);
}

/**
 * @brief Send a adc_status message
 * @param chan MAVLink channel to send the message
 *
 * @param adc_port1 adc status of the adc port1
 * @param adc_port2 adc status of the adc port2
 * @param bucket_status bucket_status 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_adc_status_send(mavlink_channel_t chan, uint8_t adc_port1, uint8_t adc_port2, uint8_t bucket_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_STATUS_LEN];
	_mav_put_uint8_t(buf, 0, adc_port1);
	_mav_put_uint8_t(buf, 1, adc_port2);
	_mav_put_uint8_t(buf, 2, bucket_status);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_STATUS, buf, MAVLINK_MSG_ID_ADC_STATUS_LEN, MAVLINK_MSG_ID_ADC_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_STATUS, buf, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif
#else
	mavlink_adc_status_t packet;
	packet.adc_port1 = adc_port1;
	packet.adc_port2 = adc_port2;
	packet.bucket_status = bucket_status;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_STATUS, (const char *)&packet, MAVLINK_MSG_ID_ADC_STATUS_LEN, MAVLINK_MSG_ID_ADC_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_STATUS, (const char *)&packet, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_ADC_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_adc_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t adc_port1, uint8_t adc_port2, uint8_t bucket_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, adc_port1);
	_mav_put_uint8_t(buf, 1, adc_port2);
	_mav_put_uint8_t(buf, 2, bucket_status);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_STATUS, buf, MAVLINK_MSG_ID_ADC_STATUS_LEN, MAVLINK_MSG_ID_ADC_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_STATUS, buf, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif
#else
	mavlink_adc_status_t *packet = (mavlink_adc_status_t *)msgbuf;
	packet->adc_port1 = adc_port1;
	packet->adc_port2 = adc_port2;
	packet->bucket_status = bucket_status;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_STATUS, (const char *)packet, MAVLINK_MSG_ID_ADC_STATUS_LEN, MAVLINK_MSG_ID_ADC_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_STATUS, (const char *)packet, MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE ADC_STATUS UNPACKING


/**
 * @brief Get field adc_port1 from adc_status message
 *
 * @return adc status of the adc port1
 */
static inline uint8_t mavlink_msg_adc_status_get_adc_port1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field adc_port2 from adc_status message
 *
 * @return adc status of the adc port2
 */
static inline uint8_t mavlink_msg_adc_status_get_adc_port2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field bucket_status from adc_status message
 *
 * @return bucket_status 
 */
static inline uint8_t mavlink_msg_adc_status_get_bucket_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a adc_status message into a struct
 *
 * @param msg The message to decode
 * @param adc_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_adc_status_decode(const mavlink_message_t* msg, mavlink_adc_status_t* adc_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	adc_status->adc_port1 = mavlink_msg_adc_status_get_adc_port1(msg);
	adc_status->adc_port2 = mavlink_msg_adc_status_get_adc_port2(msg);
	adc_status->bucket_status = mavlink_msg_adc_status_get_bucket_status(msg);
#else
	memcpy(adc_status, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_ADC_STATUS_LEN);
#endif
}
