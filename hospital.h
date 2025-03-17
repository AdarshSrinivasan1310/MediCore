#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED
#include "appointment.h"
#include "patient.h"
#include "staff.h"
#include <iostream>
using namespace std;
#include <vector>

class Hospital {
private:
    vector<Patient> patients;
    vector<Staff> staffs;
    vector<Appointment> appointments;

public:
    void addPatient() {
        string name, gender, type;
        int age;
        cout << "Enter patient's name: ";
        cin >> name;
        cout << "Enter patient's age: ";
        cin >> age;
        cout << "Enter patient's gender: ";
        cin >> gender;
        cout << "Enter patient's type (Inpatient/Outpatient): ";
        cin >> type;
        patients.push_back(Patient(name, age, gender, type));
    }

    void addStaff() {
        string name, gender, role;
        int age;
        cout << "Enter staff's name: ";
        cin >> name;
        cout << "Enter staff's age: ";
        cin >> age;
        cout << "Enter staff's gender: ";
        cin >> gender;
        cout << "Enter staff's role: ";
        cin >> role;
        staffs.push_back(Staff(name, age, gender, role));
    }

    void makeAppointment() {
        string patientName, doctorName, date;
        cout << "Enter patient's name: ";
        cin >> patientName;
        cout << "Enter doctor's name: ";
        cin >> doctorName;
        cout << "Enter date of appointment (YYYY-MM-DD): ";
        cin >> date;
        appointments.push_back(Appointment(patientName, doctorName, date));
    }

    void displayPatients() const {
        cout << "Patients List:" << endl;
        for (const auto& patient : patients) {
            patient.displayDetails();
            cout << endl;
        }
    }

    void displayStaffs() const {
        cout << "Staffs List:" << endl;
        for (const auto& staff : staffs) {
            staff.displayDetails();
            cout << endl;
        }
    }

    void displayAppointments() const {
        cout << "Appointments List:" << endl;
        for (const auto& appointment : appointments) {
            appointment.displayDetails();
            cout << endl;
        }
    }


    void loadDataFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            patients.clear();
            staffs.clear();
            appointments.clear();
            string line;
            while (getline(file, line)) {
                if (line == "Patient") {
                    string name, gender, type;
                    int age;
                    getline(file, name);
                    file >> age >> gender >> type;
                    patients.push_back(Patient(name, age, gender, type));
                } else if (line == "Staff") {
                    string name, gender, role;
                    int age;
                    getline(file, name);
                    file >> age >> gender >> role;
                    staffs.push_back(Staff(name, age, gender, role));
                } else if (line == "Appointment") {
                    string patientName, doctorName, date;
                    getline(file, patientName);
                    file >> doctorName >> date;
                    appointments.push_back(Appointment(patientName, doctorName, date));
                }
            }
            file.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

    void saveDataToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& patient : patients) {
            file << "Patient\n";
            file << patient.getName() << "\n";
            file << patient.getAge() << "\n";
            file << patient.getGender() << "\n";
            file << patient.getType() << "\n";
        }
        for (const auto& staff : staffs) {
            file << "Staff\n";
            file << staff.getName() << "\n";
            file << staff.getAge() << "\n";
            file << staff.getGender() << "\n";
            file << staff.getRole()<< "\n";
        }
        for (const auto& appointment : appointments) {
            file << "Appointment\n";
            file << appointment.getPatientName() << "\n";
            file << appointment.getDoctorName() << "\n";
            file << appointment.getDate() << "\n";
        }
            file.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }
};


#endif // HOSPITAL_H_INCLUDED
