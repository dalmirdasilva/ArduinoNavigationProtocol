#include "AckMessage.h"
#include <Message.h>

AckMessage::AckMessage(uint8_t ackedId) :
        Message(ACK_MESSAGE_TYPE) {
    _payload.ackedId = ackedId;
    payloadSize = (uint8_t) sizeof(_payload);
    payload = (uint8_t *) &_payload;
    flags = NAVIGATION_PROTOCOL_ACK_MESSAGE_FLAGS;
}

AckMessage::Payload *AckMessage::getPayload() {
    return &_payload;
}
