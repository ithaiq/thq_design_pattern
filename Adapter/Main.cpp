//
// Created by Mac on 2023/8/1.
//
#include <string>

using namespace std;

class Profit {
public:
    float getProfit() {
        return 1.0;
    }
};

class USDProfit {
public:
    float getUSDProfit(const string &name, const string &addr) {
        return 2.0;
    };
};

int main() {
    Profit profit;
    float profitNum = profit.getProfit();

    USDProfit usdProfit;
    float usdProfitNum = usdProfit.getUSDProfit("abc", "123");
    usdProfitNum = usdProfitNum * 7.0;
}