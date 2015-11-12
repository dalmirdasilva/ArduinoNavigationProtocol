#include "SimpleNavigationProtocol.h"
#include <Stream.h>

SimpleNavigationProtocol::SimpleNavigationProtocol(Stream *stream)
        : stream(stream), connected(false), fn(0) {
}

SimpleNavigationProtocol::SimpleNavigationProtocol(Stream *stream, void (*fn)(Message *message))
    : stream(stream), connected(false), fn(fn) {
}

uint8_t SimpleNavigationProtocol::connect() {
    return 0;
}

uint8_t SimpleNavigationProtocol::isConnected() {
    return 0;
}

uint8_t SimpleNavigationProtocol::sendMessage(Message *message) {
    uint8_t len = message->getLength();
    uint8_t buf[len];
    message->pack(buf);
    size_t written = stream->write(buf, len);
    if (written != len) {
        return 0;
    }
    return 1;
}

void SimpleNavigationProtocol::registerMessageReceivedHandler(void (*fn)(Message *message)) {
    this->fn = fn;
}

void SimpleNavigationProtocol::onInterrupt() {

}
