#include "../Message/Message.h"
#include "../Message/GyroscopeMessage.h"
#include <stdio.h>

int main() {
    int i = 0;
    GyroscopeMessage m = GyroscopeMessage();
    unsigned char buf[m.getLength()];
    m.pack(buf);
    printf("%d\n", m.getLength());
    for (; i < m.getLength(); i++) {
        printf("%d\n", buf[i]);
    }
    return 0;
}
