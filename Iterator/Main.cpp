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

class Company {
public:
    vector<Staff> staffVec;

    void addStaff(const string &name, int age, const string &info) {
        Staff staff(name, age, info);
        staffVec.push_back(staff);
    }
};

class Company2 {
public:
    Staff *head = new Staff("", 0, "");

    void addStaff(const string &name, int age, const string &info) const {
        Staff *p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = new Staff(name, age, info);
    }
};

int main() {
    Company company;
    company.addStaff("name1", 1, "test1");
    company.addStaff("name2", 2, "test2");
    for (const Staff &staff: company.staffVec) {
        printf("name:%s,age:%d,info:%s\n", staff.name.c_str(), staff.age, staff.info.c_str());
    }
    Company2 company2;
    company2.addStaff("name1", 1, "test1");
    company2.addStaff("name2", 2, "test2");
    Staff *p = company2.head;
    while (p->next != nullptr) {
        p = p->next;
        printf("name:%s,age:%d,info:%s\n", p->name.c_str(), p->age, p->info.c_str());
    }
}