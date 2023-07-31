//
// Created by Mac on 2023/7/31.
//
#include <string>

using namespace std;

class SystemConfig {
public:
    string mMysqlAddr;
    string mMysqlDb;
    string mRedisAddr;
    string mRedisDb;

    SystemConfig() {};

    SystemConfig(const string &mMysqlAddr, const string &mMysqlDb, const string &mRedisAddr, const string &mRedisDb)
            : mMysqlAddr(mMysqlAddr), mMysqlDb(mMysqlDb), mRedisAddr(mRedisAddr), mRedisDb(mRedisDb) {};


};

class SystemConfigBuilder {
public:
    SystemConfig cfg;

    [[nodiscard]] SystemConfig getSystemConfig() const {
        return cfg;
    }

    void SetRedis(const string &redisAddr, const string &redisDb) {
        cfg.mRedisAddr = redisAddr;
        cfg.mRedisDb = redisDb;
    }

    void SetMysql(const string &mysqlAddr, const string &mysqlDb) {
        cfg.mMysqlAddr = mysqlAddr;
        cfg.mMysqlDb = mysqlDb;
    }
};

class System {
private:
    SystemConfigBuilder builder;
public:
    SystemConfig buildSystemConfig() {
        builder.SetRedis("r1", "r2");
        return builder.getSystemConfig();
    }
};

int main() {
    SystemConfig config("test", "test2", "test3", "test4");
    printf("config mysqlAddr:%s,mMysqlDb:%s,mRedisAddr:%s,mRedisDb:%s\n",
           config.mMysqlAddr.c_str(),
           config.mMysqlDb.c_str(),
           config.mRedisAddr.c_str(),
           config.mRedisDb.c_str()
    );
    SystemConfigBuilder builder;
    builder.SetMysql("test11", "test12");
    builder.SetRedis("test21", "test22");
    SystemConfig config2 = builder.getSystemConfig();
    printf("config2 mysqlAddr:%s,mMysqlDb:%s,mRedisAddr:%s,mRedisDb:%s\n",
           config2.mMysqlAddr.c_str(),
           config2.mMysqlDb.c_str(),
           config2.mRedisAddr.c_str(),
           config2.mRedisDb.c_str()
    );
    return 0;
}