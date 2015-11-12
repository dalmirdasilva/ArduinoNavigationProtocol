#include <Stream.h>
#include <Message.h>

class SimpleNavigationProtocol {

    Stream *stream;

    uint8_t connected;

    void (*fn)(Message *message);

public:

    SimpleNavigationProtocol(Stream *stream);

    SimpleNavigationProtocol(Stream *stream, void (*fn)(Message *message));

    uint8_t connect();

    uint8_t isConnected();

    static void onInterrupt();

    uint8_t sendMessage(Message *message);

    void registerMessageReceivedHandler(void (*fn)(Message *message));
};
