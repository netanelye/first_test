#ifndef __DATE_H
#define __DATE_H

#pragma warning (disable:4996)

#include <iostream>
#include <string.h>
using namespace std;


class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day=01, int month=01, int year=2020);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getYear() const { return year; }
	int getMonth()const { return month; }
	int getDay() const { return day; }
	void ShowDate();

	friend ostream& operator<<(ostream& os, const Date& d)
	{
		os <<d.day << "/" << d.month << "/" << d.year;
		return os;
	}
};

#endif // !__DATE_H