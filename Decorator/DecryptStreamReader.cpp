//
// Created by Mac on 2023/7/28.
//

#include "DecryptStreamReader.h"

DecryptStreamReader::DecryptStreamReader(StreamReader *reader) : DecoratorStreamReader(reader) {}

int DecryptStreamReader::open(const string &url) {
    return reader->open(url);
}

int DecryptStreamReader::close() {
    return reader->close();
}

int DecryptStreamReader::read(uint8_t *buf, int wantLen) {
    printf("DecryptStreamReader decrpyt\n");
    return reader->read(buf, wantLen);
}
