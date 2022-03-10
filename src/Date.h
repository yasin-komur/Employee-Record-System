#ifndef ASSIGNMENT2SCRATCH_DATE_H
#define ASSIGNMENT2SCRATCH_DATE_H
#include <iostream>

class Date
{
private:
    int day, month, year;
public:
    Date(std::string date);
    friend std::ostream& operator<<(std::ostream& os, const Date& dt);

    int getMonth() const;

    int getYear() const;

    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;
};

std::ostream& operator<<(std::ostream& os, const Date& dt);


#endif //ASSIGNMENT2SCRATCH_DATE_H
