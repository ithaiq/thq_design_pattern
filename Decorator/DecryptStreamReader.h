//
// Created by Mac on 2023/7/28.
//

#ifndef DESIGN_DECRYPTSTREAMREADER_H
#define DESIGN_DECRYPTSTREAMREADER_H

#include "DecoratorStreamReader.h"

class DecryptStreamReader : public DecoratorStreamReader {
public:
    explicit DecryptStreamReader(StreamReader *reader);

    int open(const string &url) override;

    int close() override;

    int read(uint8_t *buf, int wantLen) override;
};


#endif //DESIGN_DECRYPTSTREAMREADER_H
