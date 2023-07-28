//
// Created by Mac on 2023/7/28.
//

#include "FileStreamReader.h"
#include "HttpStreamReader.h"
#include "DecryptStreamReader.h"
#include "DecodeStreamReader.h"

int main() {
    HttpStreamReader reader;
    DecryptStreamReader dps(&reader);
    DecodeStreamReader ds(&dps);
//    reader->open("/Users/mac/code/c++/design/test.txt");
    ds.open("https://www.baidu.com");
    while (1) {
        uint8_t buf[1024];
        int ret = ds.read(buf, 1024);
        if (ret <= 0) {
            break;
        }
        for (int i = 0; i < ret; i++) {
            printf("%c", buf[i]);
        }
        printf("\n");
    }
    ds.close();
}