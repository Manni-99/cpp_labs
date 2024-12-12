#include <ctime>  // time and localtime
#include "date.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
    if (!isValid()) {
        throw std::invalid_argument("Invalid date");
    }
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
    day++;
    if (day > daysPerMonth[month - 1] + (isLeapYear() && month == 2)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

bool Date::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isValid() const {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysPerMonth[month - 1] + (isLeapYear() && month == 2)) return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setw(4) << std::setfill('0') << date.year << '-'
       << std::setw(2) << std::setfill('0') << date.month << '-'
       << std::setw(2) << std::setfill('0') << date.day;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    int y, m, d;
    char dash1, dash2;

    // Save the current stream state in case input fails
    std::istream::sentry sentry(is);
    if (sentry) {
        std::string input;
        is >> input;
        std::istringstream ss(input);

        if ((ss >> y >> dash1 >> m >> dash2 >> d) && dash1 == '-' && dash2 == '-') {
            Date temp(y, m, d); // Validate the date
            date = temp;        // Only assign if valid
        } else {
            is.setstate(std::ios_base::failbit); // Mark the stream as failed
        }
    }
    return is;
}