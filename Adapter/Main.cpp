//
// Created by Mac on 2023/8/1.
//
#include <string>

using namespace std;

class Profit {
public:
    virtual float getProfit() {
        return 1.0;
    }
};

class USDProfit {
public:
    float getUSDProfit(const string &name, const string &addr) {
        return 2;
    };
};

class USDAdapter : public Profit, public USDProfit {
public:
    float getProfit() {
        float usdProfitNum = getUSDProfit("abc", "123");
        return usdProfitNum * 7.0;;
    }
};

int main() {
    Profit profit;
    float profitNum = profit.getProfit();

    USDProfit usdProfit;
    float usdProfitNum = usdProfit.getUSDProfit("abc", "123");
    usdProfitNum = usdProfitNum * 7.0;
    printf("usdProfitNum:%f\n", usdProfitNum);

    USDAdapter usdAdapter;
    printf("usdProfitNum1:%f\n", usdAdapter.getProfit());

    Profit *usdAdapter2 = new USDAdapter();
    printf("usdProfitNum2:%f\n", usdAdapter2->getProfit());
    delete usdAdapter2;
}