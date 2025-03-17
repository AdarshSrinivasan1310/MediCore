#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED

class Appointment {
private:
    string patientName;
    string doctorName;
    string date;
public:
    Appointment() :Appointment("","",""){}
    Appointment(string p, string d, string dt) : patientName(p), doctorName(d), date(dt) {}

    void displayDetails() const {
        cout << "Patient: " << patientName << endl;
        cout << "Doctor: " << doctorName << endl;
        cout << "Date: " << date << endl;
    }
    string getPatientName() const
    {
        return patientName;
    }
    string getDoctorName() const
    {
        return doctorName;
    }
    string getDate() const
    {
        return date;
    }
};

#endif // APPOINTMENT_H_INCLUDED
