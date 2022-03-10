#ifndef ASSIGNMENT2SCRATCH_PERMANENTEMPLOYEE_H
#define ASSIGNMENT2SCRATCH_PERMANENTEMPLOYEE_H

#include "Employee.h"

class PermanentEmployee : public Employee{
public:
    PermanentEmployee(int employeeNumber, int employeeType, const std::string &name, const std::string &surname,
                      const std::string &title, double salary, const Date &birthDate, const Date &appointmentDate,
                      int otherInstitutions);
};


#endif