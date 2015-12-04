#include "MessageParser.h"
#include <Stream.h>

MessageParser::MessageParser(Stream *stream) :
        stream(stream), fn(0), state(READY), receivedBufferPointer(0) {
}

MessageParser::MessageParser(Stream *stream, void (*fn)(Message *message)) :
        stream(stream), fn(fn), state(READY), receivedBufferPointer(0) {
}

void MessageParser::registerMessageParsedHandler(void (*fn)(Message *message)) {
    this->fn = fn;
}

void MessageParser::parse() {
    int available;
    while ((available = stream->available()) > 0) {
        unsigned char buff[available];
        int read = stream->readBytes(buff, available);
        parseBuffer(buff, read);
    }
}

void MessageParser::parseBuffer(unsigned char *buff, int count) {
    int i;
    unsigned char c;
    for (i = 0; i < count; i++) {
        c = buff[i];
        parseByte(c);
    }
}

void MessageParser::notifyMessageParsed(Message *message) {
    fn(message);
}

void MessageParser::parseByte(unsigned char b) {
    uint8_t nextState;
    switch (state) {

    case ParserState::READY:
        receivedBufferPointer = 0;
        memset(receivedBuffer, 0, MAX_MESSAGE_SIZE);
        receivedBuffer[receivedBuffer++] = b;
        nextState = ParserState::TYPE_PARSED;
        break;

    case ParserState::TYPE_PARSED:
        nextState = ParserState::FLAGS_PARSED;
        receivedBuffer[receivedBuffer++] = b;
        break;

    case ParserState::FLAGS_PARSED:
        nextState = ParserState::PAYLOAD_PARSING;
        receivedBuffer[receivedBuffer++] = b;
        break;

    case ParserState::PAYLOAD_PARSING:
        nextState = ParserState::FLAGS_PARSED;
        receivedBuffer[1] = b;
        break;
    }
    if (nextState == ParserState::READY) {
        Message *message = instantiateParsedMessage();
        notifyMessageParsed();
    }
    state = nextState;
}

