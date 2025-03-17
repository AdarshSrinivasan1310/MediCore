#include <iostream>
using namespace std;

#include <fstream>
#include <vector>
#include <string>
#include "person.h"
#include "appointment.h"
#include "patient.h"
#include "staff.h"
#include "hospital.h"
int main()
{
    Hospital hospital;
    cout << "Loading data from file..." << endl;
    hospital.loadDataFromFile("hospital_data.txt");
    int choice;
    do
    {
        cout << "\nHospital Management System Menu" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Add Staff" << endl;
        cout << "3. Make Appointment" << endl;
        cout << "4. Display Patients" << endl;
        cout << "5. Display Staffs" << endl;
        cout << "6. Display Appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            hospital.addPatient();
            break;
        case 2:
            hospital.addStaff();
            break;
        case 3:
            hospital.makeAppointment();
            break;
        case 4:
            hospital.displayPatients();
            break;
        case 5:
            hospital.displayStaffs();
            break;
        case 6:
            hospital.displayAppointments();
            break;
        case 7:
            cout << "Saving data to file..." << endl;
            hospital.saveDataToFile("hospital_data.txt");
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
        }
    }
    while (choice != 7);
    return 0;
}
