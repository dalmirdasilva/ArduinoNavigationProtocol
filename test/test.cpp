#include "../Message/Message.h"
#include "../Message/RCRawMessage.h"
#include "../Message/AckMessage.h"
#include "../Message/SysStatusMessage.h"
#include <stdio.h>

int main() {
    int i = 0;
    uint8_t umpackResult;

    RCRawMessage m0 = RCRawMessage();
    RCRawMessage m1 = RCRawMessage();

    SysStatusMessage m2 = SysStatusMessage();
    SysStatusMessage m3 = SysStatusMessage();

    m0.getPayload()->setChannel1(101);
    m0.getPayload()->setChannel2(102);
    m0.getPayload()->setChannel3(103);
    m0.getPayload()->setChannel4(104);
    m0.getPayload()->setChannel5(105);
    m0.getPayload()->setChannel6(106);
    m0.getPayload()->setChannel7(107);
    m0.getPayload()->setChannel8(108);

    m2.getPayload()->setBatteryRemaining(109);
    m2.getPayload()->setBatteryVoltage(110);

    unsigned char buf[m0.getLength()];
    m0.pack(buf);
    umpackResult = m1.unpack(buf);
    if (umpackResult != Message::UNPACK_SUCCESS) {
        printf("Error. umpachResult: %d\n", umpackResult);
    }

    unsigned char buf2[m2.getLength()];
    m2.pack(buf2);
    umpackResult = m3.unpack(buf2);
    if (umpackResult != Message::UNPACK_SUCCESS) {
        printf("Error. umpachResult: %d\n", umpackResult);
    }

    printf("getChannel1: %d\n", m1.getPayload()->getChannel1());
    printf("getChannel3: %d\n", m1.getPayload()->getChannel2());
    printf("getChannel3: %d\n", m1.getPayload()->getChannel3());
    printf("getChannel4: %d\n", m1.getPayload()->getChannel4());
    printf("getChannel5: %d\n", m1.getPayload()->getChannel5());
    printf("getChannel6: %d\n", m1.getPayload()->getChannel6());
    printf("getChannel7: %d\n", m1.getPayload()->getChannel7());
    printf("getChannel8: %d\n", m1.getPayload()->getChannel8());

    printf("setBatteryRemaining: %d\n", m3.getPayload()->getBatteryRemaining());
    printf("setBatteryVoltage: %d\n", m3.getPayload()->getBatteryVoltage());
    return 0;
}
