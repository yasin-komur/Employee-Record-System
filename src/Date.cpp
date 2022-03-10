#include "Date.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

Date::Date(string date)
    {
            int array[3];
            istringstream stream (date);
            string splitted;
            int index = 0;
            while (getline(stream,splitted,'-')){
                array[index] = stoi(splitted);
                index ++;
            }

        day = array[0]; month = array[1]; year = array[2];
    }

ostream &operator<(ostream &os, const Date &dt) {

}


ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.day << '-' << dt.month << '-' << dt.year;
    return os;
}

bool Date::operator<(const Date &rhs) const {
    if (year < rhs.year)
        return true;
    else if (year == rhs.year && month < rhs.month)
        return true;
    else if (year == rhs.year && month == rhs.month && day < rhs.day)
        return true;
    return false;
}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}



int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}
