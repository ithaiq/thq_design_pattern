//
// Created by Mac on 2023/7/28.
//

#include "DecodeStreamReader.h"

DecodeStreamReader::DecodeStreamReader(StreamReader *reader) : DecoratorStreamReader(reader) {}

int DecodeStreamReader::open(const string &url) {
    return reader->open(url);
}

int DecodeStreamReader::close() {
    return reader->close();
}

int DecodeStreamReader::read(uint8_t *buf, int wantLen) {
    printf("DecodeStreamReader decrpyt\n");
    return reader->read(buf, wantLen);
}
