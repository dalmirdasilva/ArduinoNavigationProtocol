#include <Message.h>

#ifndef SIMPLE_NAVIGATION_PROTOCOL_GPS_MESSAGE
#define SIMPLE_NAVIGATION_PROTOCOL_GPS_MESSAGE

#define SNP_GPS_MESSAGE_FLAGS           0x00

class GpsMessage : public Message {

    struct Payload {
        unsigned char x;
    } _payload;

public:

    GpsMessage();
};

#endif // SIMPLE_NAVIGATION_PROTOCOL_GPS_MESSAGE
