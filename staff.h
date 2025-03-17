#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED
#include <iostream>
#include "person.h"

using namespace std;


class Staff : public Person {
private:
    string role;
public:
    Staff():Staff("",0,"","") {}
    Staff(string n, int a, string g, string r) : Person(n, a, g), role(r) {}

    void displayDetails() const {
        Person::displayDetails();
        cout << "Role: " << role << endl;
    }
    string getRole() const
    {
        return role;
    }
};



#endif // STAFF_H_INCLUDED
