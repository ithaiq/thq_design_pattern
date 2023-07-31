//
// Created by Mac on 2023/7/31.
//
#include <string>
#include <iostream>

using namespace std;

class SystemConfig {
public:
    string mMysqlAddr;
    string mMysqlDb;
    string mRedisAddr;
    string mRedisDb;

    SystemConfig(const string &mMysqlAddr, const string &mMysqlDb, const string &mRedisAddr, const string &mRedisDb)
            : mMysqlAddr(mMysqlAddr), mMysqlDb(mMysqlDb), mRedisAddr(mRedisAddr), mRedisDb(mRedisDb) {}
};

int main() {
    SystemConfig config("test", "test2", "test3", "test4");
    return 0;
}