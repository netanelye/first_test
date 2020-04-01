#pragma once
#ifndef __FEEDBACK_H
#define _FEEDBACK_H

#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

#include "Date.h"


class Feedback
{
private:
	char* writer;
	Date date;
	char* content;
public:
	Feedback(const char* writer, Date& date, const char* content);
	~Feedback();
	Feedback(const Feedback& other);
	Feedback(Feedback&& f);
	void setDate(int day, int month, int year);
	void printFeedback();
	friend ostream& operator<<(ostream& os, const Feedback& feedback);
};

#endif // ! __FEEDBACK_H