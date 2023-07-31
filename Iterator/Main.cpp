//
// Created by Mac on 2023/7/31.
//
#include <string>
#include <vector>

using namespace std;

class Staff {
public:
    string name;
    int age;
    string info;

    Staff(const string &name, int age, const string &info) : name(name), age(age), info(info) {}
};

class Company {
public:
    vector<Staff> staffVec;

    void addStaff(const string &name, int age, const string &info) {
        Staff staff(name, age, info);
        staffVec.push_back(staff);
    }
};

int main() {
    Company company;
    company.addStaff("name1", 1, "test1");
    company.addStaff("name2", 2, "test2");
    for (const Staff &staff: company.staffVec) {
        printf("name:%s,age:%d,info:%s\n", staff.name.c_str(), staff.age, staff.info.c_str());
    }
}