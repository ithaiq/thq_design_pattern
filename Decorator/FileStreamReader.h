//
// Created by Mac on 2023/7/28.
//

#ifndef DESIGN_FILESTREAMREADER_H
#define DESIGN_FILESTREAMREADER_H

#include <iostream>

using namespace std;

class FileStreamReader {
public:
    int open(const string &url);

    int close();

    int read(uint8_t *buf, int wantLen);

private:
    FILE *file = nullptr;
};


#endif //DESIGN_FILESTREAMREADER_H
