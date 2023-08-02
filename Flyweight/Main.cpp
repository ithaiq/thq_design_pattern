//
// Created by Mac on 2023/8/2.
//
#include <stdint.h>
#include <iostream>


class Buffer {
public:
    Buffer(int len) {
        bufLen = len;
        buf = (uint8_t *) malloc(bufLen);
    }

    ~Buffer() {
        if (buf != nullptr) {
            free(buf);
            buf = nullptr;
        }
        bufLen = 0;
    }

    uint8_t *buf = nullptr;
    int bufLen = 0;
};

int main() {
    Buffer *buf = new Buffer(128);
    buf->buf;
    buf->bufLen;
    delete buf;
    return 0;
}