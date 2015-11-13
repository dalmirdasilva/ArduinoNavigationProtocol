#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_GPS_MESSAGE
#define NAVIGATION_PROTOCOL_GPS_MESSAGE

#define NAVIGATION_PROTOCOL_GPS_MESSAGE_FLAGS           0x00

class GpsMessage: public Message {

    struct Payload {

        int32_t latitude;
        int32_t longitude;
        int32_t altitude;

    public:

        Payload() :
                latitude(0), longitude(0), altitude(0) {
        }

        int32_t getLatitude() const {
            return latitude;
        }

        void setLatitude(int32_t latitude) {
            this->latitude = latitude;
        }

        int32_t getLongitude() const {
            return longitude;
        }

        void setLongitude(int32_t longitude) {
            this->longitude = longitude;
        }
    } _payload;

public:

    GpsMessage();

    Payload *getPayload();
};

#endif // NAVIGATION_PROTOCOL_GPS_MESSAGE
