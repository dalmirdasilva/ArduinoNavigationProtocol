#include "NavigationProtocol.h"
#include <Stream.h>

NavigationProtocol::NavigationProtocol(Stream *stream) :
        stream(stream), connected(false), fn(0) {
}

NavigationProtocol::NavigationProtocol(Stream *stream, void (*fn)(Message *message)) :
        stream(stream), connected(false), fn(fn) {
}

uint8_t NavigationProtocol::connect() {
    return 0;
}

uint8_t NavigationProtocol::isConnected() {
    return 0;
}

uint8_t NavigationProtocol::sendMessage(Message *message) {
    uint8_t len = message->getLength();
    uint8_t buf[len];
    message->pack(buf);
    size_t written = stream->write(buf, len);
    if (written != len) {
        return 0;
    }
    return 1;
}

void NavigationProtocol::registerMessageReceivedHandler(void (*fn)(Message *message)) {
    this->fn = fn;
}

void NavigationProtocol::onInterrupt() {

}
