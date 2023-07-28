//
// Created by Mac on 2023/7/28.
//

#ifndef DESIGN_DECODESTREAMREADER_H
#define DESIGN_DECODESTREAMREADER_H


#include "StreamReader.h"
#include "DecoratorStreamReader.h"

class DecodeStreamReader : public DecoratorStreamReader {
public:
    explicit DecodeStreamReader(StreamReader *reader);

    int open(const string &url) override;

    int close() override;

    int read(uint8_t *buf, int wantLen) override;
};


#endif //DESIGN_DECODESTREAMREADER_H
