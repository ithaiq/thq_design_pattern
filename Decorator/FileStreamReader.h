//
// Created by Mac on 2023/7/28.
//

#ifndef DESIGN_FILESTREAMREADER_H
#define DESIGN_FILESTREAMREADER_H

#include <iostream>
#include "StreamReader.h"

using namespace std;

class FileStreamReader : public StreamReader {
public:
    virtual int open(const string &url) override;

    virtual int close() override;

    virtual int read(uint8_t *buf, int wantLen) override;

private:
    FILE *file = nullptr;
};


#endif //DESIGN_FILESTREAMREADER_H
