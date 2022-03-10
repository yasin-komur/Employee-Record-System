#include "TemporaryEmployee.h"


TemporaryEmployee::TemporaryEmployee(int employeeNumber, int employeeType, const std::string &name,
                                     const std::string &surname, const std::string &title, double salary,
                                     const Date &birthDate, const Date &appointmentDate, int otherInstitutions)
        : Employee(employeeNumber, employeeType, name, surname, title, salary, birthDate, appointmentDate,
                   otherInstitutions) {}
