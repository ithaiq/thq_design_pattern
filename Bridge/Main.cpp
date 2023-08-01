//
// Created by Mac on 2023/8/1.
//

//面对排列组合多维度的需求
#include <string>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class OneShape : public Shape {
public:
    virtual void draw() override {
        printf("draw one");
    }
};

class TwoShape : public Shape {
public:
    virtual void draw() override {
        printf("draw two");
    }
};

class Color {
public:
    virtual void getColor() = 0;
};

class BlueColor : public Color {
public:
    virtual void getColor() override {
        printf("blue\n");
    }
};

class BlackColor : public Color {
public:
    virtual void getColor() override {
        printf("black\n");
    }
};
