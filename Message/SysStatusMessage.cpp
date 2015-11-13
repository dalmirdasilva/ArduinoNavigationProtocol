#include "SysStatusMessage.h"
#include <Message.h>

SysStatusMessage::SysStatusMessage() :
        Message(SYS_STATUS_MESSAGE_TYPE) {
    flags = NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE_FLAGS;
    payloadSize = (uint8_t) sizeof(_payload);
    payload = (uint8_t *) &_payload;
}

SysStatusMessage::Payload *SysStatusMessage::getPayload() {
    return &_payload;
}
