#include "ConnMessage.h"
#include <Message.h>

ConnMessage::ConnMessage() :
        Message(CONN_MESSAGE_TYPE) {
    payloadSize = (uint8_t) sizeof(_payload);
    payload = (uint8_t *) &_payload;
    flags = NAVIGATION_PROTOCOL_CONN_MESSAGE_FLAGS;
}

ConnMessage::Payload *ConnMessage::getPayload() {
    return &_payload;
}
