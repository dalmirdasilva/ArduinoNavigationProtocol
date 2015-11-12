#include "GpsMessage.h"
#include <Message.h>

GpsMessage::GpsMessage()
        : Message(GPS_MESSAGE_TYPE) {
    payloadSize = (uint8_t) sizeof(_payload);
    flags = SNP_GPS_MESSAGE_FLAGS;
    payload = (uint8_t *) &_payload;
}
