//
// Created by Mac on 2023/7/28.
//

#ifndef DESIGN_HTTPSTREAMREADER_H
#define DESIGN_HTTPSTREAMREADER_H


#include "StreamReader.h"
#include <vector>

class HttpStreamReader : public StreamReader {
public:
    virtual int open(const string &url) override;

    virtual int close() override;

    virtual int read(uint8_t *buf, int wantLen) override;

    vector<uint8_t> cache;
    int pos =0;
};


#endif //DESIGN_HTTPSTREAMREADER_H
