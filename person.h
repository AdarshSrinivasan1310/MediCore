#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
using namespace std;


class Person {
private:
    string name;
    int age;
    string gender;
public:
    Person() :Person("",0,""){}
    Person(string n, int a, string g) : name(n), age(a), gender(g) {}

    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
    string getName() const
    {
        return this->name;
    }
    int getAge() const
    {
        return age;
    }
    string getGender() const
    {
        return gender;
    }
};
#endif // PERSON_H_INCLUDED
