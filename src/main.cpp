#include <iostream>
#include "CircularArrayLinkedList.h"
#include "DoubleDynamicLinkedList.h"
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include <bits/stdc++.h>
#include "Date.h"
#include <string>

using namespace std;

bool sortNumbers(const Employee *emp1, const Employee *emp2) {
    return (emp1->getEmployeeNumber() < emp2->getEmployeeNumber());
}

bool sortAppointmentDate(const Employee *emp1, const Employee *emp2) {
    return (emp1->getAppointmentDate() < emp2->getAppointmentDate());
}

bool sortReverseDate(const Employee *emp1, const Employee *emp2) {
    return (emp1->getAppointmentDate() > emp2->getAppointmentDate());
}


int main() {
    vector<Employee *> temp;
    CircularArrayLinkedList circularArray;
    DoubleDynamicLinkedList doubleLL;

    string menu = "_ Employee Recording System _\n"
                  "1) Appointment of a new employee\n"
                  "2) Appointment of a transferred employee\n"
                  "3) Updating the the title and salary coefficient of an employee\n"
                  "4) Deleting of an employee\n"
                  "5) Listing the information of an employee\n"
                  "6) Listing employees ordered by employee number\n"
                  "7) Listing employees ordered by appointment date\n"
                  "8) Listing employees appointed after a certain date\n"
                  "9) Listing employees assigned in a given year\n"
                  "10) Listing employees born before a certain date\n"
                  "11) Listing employees born in a particular month\n"
                  "12) Listing the information of the last assigned employee with a given title\n";

    while (true) {
        cout << menu << endl;
        int command;
        cin >> command;

        int empNum;
        int empType;
        string name;
        string surname;
        string title;
        double salaryCoefficient;
        string birthDate;
        string appointmentDate;
        int lengthOfServiceDate;
        if (command == 1) {
            cout << "Please type the employee number" << endl;
            cin >> empNum;
            if (!(circularArray.contains(empNum)) && !(doubleLL.contains(empNum))) {
                cout << "Type the employee type" << endl;
                cin >> empType;
                cout << "Type the name" << endl;
                cin >> name;
                cout << "Type surname" << endl;
                cin >> surname;
                cout << "Type title" << endl;
                cin >> title;
                cout << "Type salary coefficient" << endl;
                cin >> salaryCoefficient;
                cout << "Type birth date" << endl;
                cin >> birthDate;
                cout << "Type appointment date" << endl;
                cin >> appointmentDate;
                if (empType == 0) {
                    TemporaryEmployee emp(empNum, empType, name, surname, title, salaryCoefficient, Date(birthDate),
                                          Date(appointmentDate), 0);
                    circularArray.insert(&emp);
                }
                if (empType == 1) {
                    PermanentEmployee emp(empNum, empType, name, surname, title, salaryCoefficient, Date(birthDate),
                                          Date(appointmentDate), 0);
                    doubleLL.insert(&emp);
                }
            } else {
                cout << "This employee has already been inserted!" << endl;
            }
        }
        if (command == 2) {
            cout << "Please type the employee number" << endl;
            cin >> empNum;
            if (!(circularArray.contains(empNum)) && !(doubleLL.contains(empNum))) {
                cout << "Type the employee type" << endl;
                cin >> empType;
                cout << "Type the name" << endl;
                cin >> name;
                cout << "Type surname" << endl;
                cin >> surname;
                cout << "Type title" << endl;
                cin >> title;
                cout << "Type salary coefficient" << endl;
                cin >> salaryCoefficient;
                cout << "Type birth date" << endl;
                cin >> birthDate;
                cout << "Type appointment date" << endl;
                cin >> appointmentDate;
                cout << "Type length of service days" << endl;
                cin >> lengthOfServiceDate;
                if (empType == 0) {
                    TemporaryEmployee emp(empNum, empType, name, surname, title, salaryCoefficient, Date(birthDate),
                                          Date(appointmentDate), lengthOfServiceDate);
                    circularArray.insert(&emp);
                }
                if (empType == 1) {
                    PermanentEmployee emp(empNum, empType, name, surname, title, salaryCoefficient, Date(birthDate),
                                          Date(appointmentDate), lengthOfServiceDate);
                    doubleLL.insert(&emp);
                }
            } else {
                cout << "This employee has already been inserted!" << endl;
            }
        }
        if (command == 3) {
            cout << "Please type of the employee number.." << endl;
            cin >> empNum;
            if (!(circularArray.contains(empNum)) && !(doubleLL.contains(empNum))) {
                cout << "This employee has not been found!" << endl;
            }
            else if (doubleLL.contains(empNum)) {
                PermanentEmployee *emp = doubleLL.find(empNum);
                cout << "Please enter the title" << endl;
                cin >> title;
                cout << "Please enter the salary coefficient" << endl;
                cin >> salaryCoefficient;
                emp->setTitle(title);
                emp->setSalary(salaryCoefficient);
            } else {
                TemporaryEmployee * emp = circularArray.find(empNum);
                cout << "Please enter the title" << endl;
                cin >> title;
                cout << "Please enter the salary coefficient" << endl;
                cin >> salaryCoefficient;
                emp->setTitle(title);
                emp->setSalary(salaryCoefficient);
            }
        }
        if (command == 4) {
            cout << "Type the employee number" << endl;
            cin >> empNum;
            if (!(circularArray.contains(empNum)) && !(doubleLL.contains(empNum))) {
                cout << "This employee has not been found!" << endl;
            }
            else if (doubleLL.contains(empNum)) {
                doubleLL.remove(empNum);
            }
            else {
                circularArray.remove(empNum);
            }
        }

        if (command == 5) {
            cout << "Type the employee number" << endl;
            cin >> empNum;
            if (!(circularArray.contains(empNum)) && !(doubleLL.contains(empNum))) {
                cout << "This employee has not been found!" << endl;
            }
            else if (doubleLL.contains(empNum)) {
                PermanentEmployee *emp = doubleLL.find(empNum);
                cout << *emp << endl;
            }
            else {
                TemporaryEmployee *emp = circularArray.find(empNum);
                cout << *emp << endl;
            }
        }
        if (command == 6) {
            temp.clear();
            circularArray.createVector(&temp);
            doubleLL.createVector(&temp);
            sort(temp.begin(), temp.end(), sortNumbers);
            for (Employee *employee : temp) {
                cout << *employee << endl;
            }
        }
        if (command == 7) {
            temp.clear();
            circularArray.createVector(&temp);
            doubleLL.createVector(&temp);
            sort(temp.begin(), temp.end(), sortAppointmentDate);
            for (Employee *employee : temp) {
                cout << *employee << endl;
            }
        }
        if (command == 8) {
            cout << "Type date" << endl;
            cin >> appointmentDate;
            Date date(appointmentDate);
            temp.clear();
            circularArray.createVector(&temp);
            doubleLL.createVector(&temp);
            sort(temp.begin(), temp.end(), sortReverseDate);
            for (Employee *employee:temp) {
                if (date < employee->getAppointmentDate()) {
                    cout << *employee << endl;
                }
            }
        }
        if (command == 9) {
            cout << "Type year" << endl;
            int year;
            cin >> year;
            temp.clear();
            circularArray.createVector(&temp);
            doubleLL.createVector(&temp);
            sort(temp.begin(), temp.end(), sortAppointmentDate);
            for (Employee *employee:temp) {
                if (year == employee->getAppointmentDate().getYear()) {
                    cout << *employee << endl;
                }
            }
        }
        if (command == 10) {
            cout << "Type the date" << endl;
            cin >> birthDate;
            Date date(birthDate);
            temp.clear();
            circularArray.createVector(&temp);
            doubleLL.createVector(&temp);
            sort(temp.begin(), temp.end(), sortNumbers);
            for (Employee *employee:temp) {
                if (date > employee->getBirthDate()) {
                    cout << *employee << endl;
                }
            }
        }
        if (command == 11) {
            cout << "Type the month" << endl;
            int month;
            cin >> month;
            temp.clear();
            circularArray.createVector(&temp);
            doubleLL.createVector(&temp);
            sort(temp.begin(), temp.end(), sortNumbers);
            for (Employee *employee:temp) {
                if (month == employee->getBirthDate().getMonth()) {
                    cout << *employee << endl;
                }
            }
        }
        if (command == 12) {
            cout << "Type the title" << endl;
            cin >> title;
            temp.clear();
            circularArray.createVector(&temp);
            doubleLL.createVector(&temp);
            sort(temp.begin(), temp.end(), sortReverseDate);
            for (Employee *employee : temp) {
                if (title == employee->getTitle()) {
                    cout << *employee << endl;
                    break;
                }
            }
        }
    }
}
