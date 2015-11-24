#include "Message.h"
#include <string.h>
#include <stdio.h>

Message::Message(uint8_t type) :
    id(_id++), type(type), flags(0), payload(0), payloadSize(0) {
}

Message::~Message() {
}

uint8_t Message::getType() const {
    return this->type;
}

uint8_t Message::getFlags() const {
    return this->flags;
}

void Message::setFlags(uint8_t flags) {
    this->flags = flags;
}

void Message::pack(uint8_t *buf) const {
    uint16_t sum = computeChecksum(this->payload);
    buf[NAVIGATION_PROTOCOL_MESSAGE_TYPE_OFFSET] = type;
    buf[NAVIGATION_PROTOCOL_MESSAGE_FLAG_OFFSET] = flags;
    buf[NAVIGATION_PROTOCOL_MESSAGE_PAYLOAD_SIZE_OFFSET] = payloadSize;
    memcpy(&buf[NAVIGATION_PROTOCOL_MESSAGE_PAYLOAD_OFFSET], this->payload, payloadSize);
    memcpy(&buf[NAVIGATION_PROTOCOL_MESSAGE_PAYLOAD_OFFSET + payloadSize], (uint8_t*) &sum,
            NAVIGATION_PROTOCOL_MESSAGE_CHECKSUM_SIZE);
}

uint8_t Message::unpack(uint8_t *buf) {
    uint16_t sum, computedSum;
    if (buf[NAVIGATION_PROTOCOL_MESSAGE_TYPE_OFFSET] != this->type) {
        return UNPACK_TYPE_MISMATCH;
    }
    computedSum = computeChecksum(&buf[NAVIGATION_PROTOCOL_MESSAGE_PAYLOAD_OFFSET]);
    memcpy((uint8_t*) &sum, &buf[NAVIGATION_PROTOCOL_MESSAGE_PAYLOAD_OFFSET + payloadSize],
    NAVIGATION_PROTOCOL_MESSAGE_CHECKSUM_SIZE);
    if (computedSum != sum) {
        return UNPACK_CHECKSUM_MISMATCH;
    }
    memcpy(this->payload, &buf[NAVIGATION_PROTOCOL_MESSAGE_PAYLOAD_OFFSET], payloadSize);
    return UNPACK_SUCCESS;
}

uint8_t Message::getLength() const {
    return NAVIGATION_PROTOCOL_MESSAGE_HEADER_SIZE + this->payloadSize + NAVIGATION_PROTOCOL_MESSAGE_CHECKSUM_SIZE;
}

uint16_t Message::computeChecksum(uint8_t* buf) const {
    uint16_t i, sum = 0;
    for (i = 0; i < NAVIGATION_PROTOCOL_MESSAGE_CHECKSUM_SIZE; i++) {
        sum += buf[i];
    }
    return sum;
}
