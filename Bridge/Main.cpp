//
// Created by Mac on 2023/8/1.
//

//面对排列组合多维度的需求
#include <string>

using namespace std;

class Color {
public:
    virtual void getColor() = 0;
};

class Shape {
public:
    virtual void draw() = 0;

    void SetColor(Color *_color) {
        color = _color;
    }

    Color *color = nullptr;
};

class OneShape : public Shape {
public:
    virtual void draw() override {
        color->getColor();
        printf("draw one");
    }
};

class TwoShape : public Shape {
public:
    virtual void draw() override {
        printf("draw two");
    }
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

int main() {
    Shape *shape = new OneShape();
    Color *color = new BlackColor();
    shape->SetColor(color);
    shape->draw();
    delete color;
    delete shape;
}