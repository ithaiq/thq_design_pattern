//
// Created by Mac on 2023/7/31.
//
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Staff {
public:
    string name;
    int age;
    string info;
    Staff *next = nullptr;

    Staff(string name, int age, string info) : name(std::move(name)), age(age), info(std::move(info)) {}
};

class Iterator {
public:
    virtual Staff first() = 0;

    virtual Staff next() = 0;

    virtual bool isEnd() = 0;
};

class Company : public Iterator {
public:
    vector<Staff> staffVec;
    int pos = 0;

    void addStaff(const string &name, int age, const string &info) {
        Staff staff(name, age, info);
        staffVec.push_back(staff);
    }

    Staff first() override {
        pos = 0;
        return staffVec[pos];
    }

    Staff next() override {
        Staff s = staffVec[pos];
        pos++;
        return s;
    }

    bool isEnd() override {
        if (pos >= staffVec.size()) {
            return true;
        }
        return false;
    }
};

class Company2 : public Iterator {
public:
    Staff *head = new Staff("", 0, "");
    Staff *cur = nullptr;

    void addStaff(const string &name, int age, const string &info) const {
        Staff *p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = new Staff(name, age, info);
    }

    Staff first() override {
        cur = head->next;
        return *cur;
    }

    Staff next() override {
        Staff *tmp = cur;
        cur = cur->next;
        return *tmp;
    }

    bool isEnd() override {
        if (cur == nullptr) {
            return true;
        }
        return false;
    }
};

void Display(Iterator *it);

int main() {
    Company company;
    company.addStaff("name1", 1, "test1");
    company.addStaff("name2", 2, "test2");
//    for (const Staff &staff: company.staffVec) {
//        printf("name:%s,age:%d,info:%s\n", staff.name.c_str(), staff.age, staff.info.c_str());
//    }
    Display(&company);
    Company2 company2;
    company2.addStaff("name1", 1, "test1");
    company2.addStaff("name2", 2, "test2");
//    Staff *p = company2.head;
//    while (p->next != nullptr) {
//        p = p->next;
//        printf("name:%s,age:%d,info:%s\n", p->name.c_str(), p->age, p->info.c_str());
//    }
    Display(&company2);
}

void Display(Iterator *it) {
    it->first();
    while (!it->isEnd()) {
        Staff staff = it->next();
        printf("name:%s,age:%d,info:%s\n", staff.name.c_str(), staff.age, staff.info.c_str());
    }
}
