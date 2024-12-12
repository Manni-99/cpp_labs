#ifndef DATE_H
#define DATE_H
#include <iostream> 
#include <sstream>
#include <string>

class Date {
public:
	Date();                    // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	int getYear() const;       // get the year
	int getMonth() const;      // get the month
	int getDay() const;        // get the day
	void next();               // advance to next day

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is, Date& date);
private:
	int year;  // the year (four digits)
	int month; // the month (1-12)
	int day;   // the day (1-..)
	static int daysPerMonth[12]; // number of days in each month

	bool isValid() const;      // Validate the date
    bool isLeapYear() const;   // Check if the year is a leap year
};

template <typename T>
std::string toString(const T& obj){
	std::ostringstream oss;
	oss << obj;
	return oss.str();
}

template <typename T>
T string_cast(const std::string& str){
	T result;
	std::istringstream stream(str);
	stream >> result;

	if(stream.fail() || !stream.eof()){
		throw std::invalid_argument("Invalid argument for conversion" + str);
	}
	return result;
}

#endif
