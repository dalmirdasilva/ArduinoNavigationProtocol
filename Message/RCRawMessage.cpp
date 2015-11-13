#include "RCRawMessage.h"
#include <Message.h>
#include <stdio.h>

RCRawMessage::RCRawMessage() :
        Message(RC_RAW_MESSAGE_TYPE) {
    flags = NAVIGATION_PROTOCOL_RC_RAW_MESSAGE_FLAGS;
    payloadSize = (uint8_t) sizeof(_payload);
    payload = (uint8_t *) &_payload;
}

RCRawMessage::Payload *RCRawMessage::getPayload() {
    return &_payload;
}
