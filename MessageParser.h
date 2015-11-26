#include <Stream.h>
#include <Message.h>

#define MAX_MESSAGE_PAYLOAD_SIZE 16
#define MAX_MESSAGE_SIZE (1 + 1 + 1 + MAX_MESSAGE_PAYLOAD_SIZE + 2)

class MessageParser {

    enum ParserState {
        READY = 0,
        TYPE_PARSED = 1,
        FLAGS_PARSED = 2,
        SIZE_PARSED = 3,
        PAYLOAD_PARSING = 4,
        PAYLOAD_PARSED = 5,
        CHECKSUM_PARSING = 6,
    };

    Stream *stream;

    void (*fn)(Message *message);

    ParserState state;

    unsigned int receivedBufferPointer;

    unsigned char receivedBuffer[MAX_MESSAGE_SIZE];

public:

    MessageParser(Stream *stream);

    MessageParser(Stream *stream, void (*fn)(Message *message));

    void registerMessageParsedHandler(void (*fn)(Message *message));

    void parse();

private:

    void notifyMessageParsed(Message *message);

    void parseBuffer(unsigned char *buff, int count);

    void parseByte(unsigned char b);
};
