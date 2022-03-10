#ifndef ASSIGNMENT2SCRATCH_TEMPORARYEMPLOYEE_H
#define ASSIGNMENT2SCRATCH_TEMPORARYEMPLOYEE_H
#include "Employee.h"

class TemporaryEmployee : public Employee {
public:
    TemporaryEmployee(int employeeNumber, int employeeType, const std::string &name, const std::string &surname,
                      const std::string &title, double salary, const Date &birthDate, const Date &appointmentDate,
                      int otherInstitutions);
};

#endif
