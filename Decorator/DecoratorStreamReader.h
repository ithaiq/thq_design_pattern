//
// Created by Mac on 2023/7/28.
//

#ifndef DESIGN_DECORATORSTREAMREADER_H
#define DESIGN_DECORATORSTREAMREADER_H

#include "StreamReader.h"

class DecoratorStreamReader : public StreamReader {
public:
    StreamReader *reader = nullptr;

    explicit DecoratorStreamReader(StreamReader *reader) : reader(reader) {}
};

#endif //DESIGN_DECORATORSTREAMREADER_H
