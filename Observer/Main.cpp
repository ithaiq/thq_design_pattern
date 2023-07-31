#include <cstdio>

//
// Created by Mac on 2023/7/31.
//
class UserWallet {
public:
    float balance = 0.0;

    float deposit(float p) {
        return balance += p;
    };

    float consume(float p) {
        return balance -= p;
    };

    float getBalance() {
        return balance;
    }
};

int main() {
    UserWallet wallet;
    wallet.deposit(100);
    for (int i = 0; i < 100; i++) {
        wallet.consume(1.0);
        printf("%f\n", wallet.getBalance());
    }
    return 0;
}