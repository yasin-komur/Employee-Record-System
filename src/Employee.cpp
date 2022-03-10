#include "Employee.h"
Employee::Employee(int employeeNumber, int employeeType, std::string name, std::string surname, std::string title, double salary,
                   const Date &birthDate, const Date &appointmentDate, int otherInstitutions) : employeeNumber(
        employeeNumber), employeeType(employeeType), name(name), surname(surname), title(title), salary(salary),
                                                                                                birthDate(birthDate),
                                                                                                appointmentDate(
                                                                                                        appointmentDate),
                                                                                                otherInstitutions(
                                                                                                        otherInstitutions) {}


int Employee::getEmployeeNumber() const {
    return employeeNumber;
}

std::string Employee::getTitle() const {
    return title;
}

void Employee::setTitle(std::string title) {
    Employee::title = title;
}


void Employee::setSalary(double salary) {
    Employee::salary = salary;
}

const Date &Employee::getBirthDate() const {
    return birthDate;
}

const Date &Employee::getAppointmentDate() const {
    return appointmentDate;
}



std::ostream &operator<<(std::ostream &os, const Employee &employee) {
    os << "Employee Number: " << employee.employeeNumber << " Employee Type: " << employee.employeeType << " Name: "
       << employee.name << " Surname: " << employee.surname << " Title: " << employee.title << " Salary Coefficient: "
       << employee.salary << " Birth Date: " << employee.birthDate << " Appointment Date: " << employee.appointmentDate
       << " Service in Other Institutions: " << employee.otherInstitutions;
    return os;
}


Employee::~Employee() {
}