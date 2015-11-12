#include "GyroscopeMessage.h"
#include <Message.h>

GyroscopeMessage::GyroscopeMessage()
        : Message(NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE_FLAGS) {
    payloadSize = (uint8_t) sizeof(_payload);
    flags = NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE_FLAGS;
    payload = (uint8_t *) &_payload;
}
