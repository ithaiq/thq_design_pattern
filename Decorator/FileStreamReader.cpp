//
// Created by Mac on 2023/7/28.
//

#include "FileStreamReader.h"


int FileStreamReader::open(const string &url) {
    file = fopen(url.c_str(), "rb");
    return 0;
}

int FileStreamReader::close() {
    if (file != nullptr) {
        fclose(file);
        file = nullptr;
    }
    return 0;
}

int FileStreamReader::read(uint8_t *buf, int wantLen) {
    return fread(buf, 1, wantLen, file);
}
