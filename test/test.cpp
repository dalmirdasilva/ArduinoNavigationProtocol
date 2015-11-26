#include "../Message/Message.h"
#include "../Message/RCRawMessage.h"
#include "../Message/AckMessage.h"
#include "../Message/SysStatusMessage.h"
#include <stdio.h>

void assetTrue(bool v, const char *testName) {
    if (v) {
        printf("(*) %s PASSED.\n", testName);
    } else {
        printf("(F) %s FAILED.\n", testName);
    }
}

void assetFalse(bool v, const char *testName) {
    assetTrue(!v, testName);
}

void assetEquals(int v0, int v1, const char *testName) {
    assetTrue(v0 == v1, testName);
}

void testRCRawMessage();
void testSysStatusMessage();

int main() {

    testRCRawMessage();
    testSysStatusMessage();
    return 0;
}

void testRCRawMessage() {
    uint8_t umpackResult;
    RCRawMessage m0 = RCRawMessage();
    RCRawMessage m1 = RCRawMessage();

    m0.getPayload()->setChannel1(101);
    m0.getPayload()->setChannel2(102);
    m0.getPayload()->setChannel3(103);
    m0.getPayload()->setChannel4(104);
    m0.getPayload()->setChannel5(105);
    m0.getPayload()->setChannel6(106);
    m0.getPayload()->setChannel7(107);
    m0.getPayload()->setChannel8(108);

    unsigned char buf[m0.getLength()];
    m0.pack(buf);
    umpackResult = m1.unpack(buf);

    assetEquals(umpackResult, Message::UNPACK_SUCCESS, "Unpack result");
    assetEquals((int) m1.getPayload()->getChannel1(), 101, "getChannel1");
    assetEquals((int) m1.getPayload()->getChannel2(), 102, "getChannel2");
    assetEquals((int) m1.getPayload()->getChannel3(), 103, "getChannel3");
    assetEquals((int) m1.getPayload()->getChannel4(), 104, "getChannel4");
    assetEquals((int) m1.getPayload()->getChannel5(), 105, "getChannel5");
    assetEquals((int) m1.getPayload()->getChannel6(), 106, "getChannel6");
    assetEquals((int) m1.getPayload()->getChannel7(), 107, "getChannel7");
    assetEquals((int) m1.getPayload()->getChannel8(), 108, "getChannel8");
}

void testSysStatusMessage() {
    uint8_t umpackResult;
    SysStatusMessage m0 = SysStatusMessage();
    SysStatusMessage m1 = SysStatusMessage();

    m0.getPayload()->setBatteryRemaining(109);
    m0.getPayload()->setBatteryVoltage(110);

    unsigned char buf[m0.getLength()];
    m0.pack(buf);
    umpackResult = m1.unpack(buf);

    assetEquals(umpackResult, Message::UNPACK_SUCCESS, "Unpack result");
    assetEquals((int) m1.getPayload()->getBatteryRemaining(), 109, "getBatteryRemaining");
    assetEquals((int) m1.getPayload()->getBatteryVoltage(), 110, "getBatteryVoltage");
}
