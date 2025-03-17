#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include <iostream>
#include "person.h"
using namespace std;

class Patient : public Person {
private:
    string type;
public:
    Patient() :Patient("",0,"",""){}
    Patient(string n, int a, string g, string t) : Person(n, a, g), type(t) {}

    void displayDetails() const {
        Person::displayDetails();
        cout << "Type: " << type << endl;
    }
    string getType() const
    {
        return type;
    }
};


#endif // PATIENT_H_INCLUDED
