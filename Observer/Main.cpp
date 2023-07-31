#include <cstdio>

//
// Created by Mac on 2023/7/31.
//
class Observer {
public:
    virtual void update() = 0;
};


class UserWallet {
public:
    float balance = 0.0;
    Observer *observer = nullptr;

    void deposit(float p) {
        balance += p;
    };

    void consume(float p) {
        balance -= p;
        observer->update();
    };

    float getBalance() {
        return balance;
    }

    void attachObserver(Observer *_observer) {
        observer = _observer;
    }
};

class UserMessageObserver : public Observer {
public:
    UserWallet *userWallet = nullptr;

    explicit UserMessageObserver(UserWallet *userWallet) : userWallet(userWallet) {
        userWallet->attachObserver(this);
    }

    void update() override {
        printf("%f notify\n", userWallet->getBalance());
        if (userWallet->getBalance() <= 3.0) {
            printf("balance low\n");
        }
    }
};


int main() {
    UserWallet wallet;
    UserMessageObserver observer(&wallet);
//    wallet.attachObserver(&observer);
    wallet.deposit(100);
    for (int i = 0; i < 100; i++) {
        wallet.consume(1.0);
//        printf("%f notify\n", wallet.getBalance());
    }
    return 0;
}