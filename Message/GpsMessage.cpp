#include "GpsMessage.h"
#include <Message.h>

GpsMessage::GpsMessage() :
        Message(GPS_MESSAGE_TYPE) {
    payloadSize = (uint8_t) sizeof(_payload);
    payload = (uint8_t *) &_payload;
    flags = NAVIGATION_PROTOCOL_GPS_MESSAGE_FLAGS;
}
