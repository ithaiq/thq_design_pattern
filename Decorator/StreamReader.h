//
// Created by Mac on 2023/7/28.
//

#ifndef DESIGN_STREAMREADER_H
#define DESIGN_STREAMREADER_H

#include <iostream>

using namespace std;

class StreamReader {
public:
    virtual int open(const string &url) = 0;

    virtual int close() = 0;

    virtual int read(uint8_t *buf, int wantLen) = 0;
};

#endif //DESIGN_STREAMREADER_H
