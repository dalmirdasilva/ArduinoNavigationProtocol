/**
 * -----------------------------------------
 * |TT|FF|SS|PP...PP|CCCC|
 *
 * T = message type
 * F = flags
 *  00000000
 *  ||||||||__ The message needs ack
 *  |||||||___
 *  ||||||____
 *  |||||_____
 *  ||||______
 *  |||_______
 *  ||________
 *  |_________
 *
 * S = the size of the payload
 * P = payload
 * C = checksum only of the payload
 */

#ifndef NAVIGATION_PROTOCOL_MESSAGE
#define NAVIGATION_PROTOCOL_MESSAGE

#include <stdint.h>

#define NAVIGATION_PROTOCOL_MESSAGE_FLAG_NEED_ACK        0x01

#define NAVIGATION_PROTOCOL_MESSAGE_HEADER_SIZE          3
#define NAVIGATION_PROTOCOL_MESSAGE_CHECKSUM_SIZE        2

#define NAVIGATION_PROTOCOL_MESSAGE_TYPE_OFFSET          0
#define NAVIGATION_PROTOCOL_MESSAGE_FLAG_OFFSET          1
#define NAVIGATION_PROTOCOL_MESSAGE_PAYLOAD_SIZE_OFFSET  2
#define NAVIGATION_PROTOCOL_MESSAGE_PAYLOAD_OFFSET       3

class Message {

protected:

    uint8_t type;

    uint8_t flags;

    uint8_t *payload;

    uint8_t payloadSize;

public:

    enum UnpackResult {
        UNPACK_SUCCESS = 0, UNPACK_CHECKSUM_MISMATCH = 1, UNPACK_TYPE_MISMATCH = 2
    };

    enum Type {
        ACK_MESSAGE_TYPE = 1, GPS_MESSAGE_TYPE = 2, GYROSCOPE_MESSAGE_TYPE = 3, SYS_STATUS_MESSAGE_TYPE = 4, RC_RAW_MESSAGE_TYPE = 5
    };

    Message(uint8_t type);

    virtual ~Message();

    uint8_t getType() const;

    uint8_t getFlags() const;

    void setFlags(uint8_t flags);

    void pack(uint8_t *buf) const;

    uint8_t unpack(uint8_t *buf);

    uint8_t getLength() const;

    uint16_t computeChecksum(uint8_t* buf) const;
};

#endif // NAVIGATION_PROTOCOL_MESSAGE
