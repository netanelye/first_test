#include "Feedback.h"

Feedback::Feedback(const char* writer, Date& date,const char* content)
{
	this->writer = strdup(writer);
	this->date = date;
	this->content = strdup(content);
}
Feedback::~Feedback()
{
	if (writer != nullptr)
		delete[] writer;
	if (content != nullptr)
		delete[] content;
}
Feedback::Feedback(const Feedback& other)
{
	this->writer = new char[strlen(other.writer) + 1];
	this->date = other.date;
	this->content = new char[strlen(other.content) + 1];
	strcpy(this->writer, writer);
	strcpy(this->content, content);
}
Feedback::Feedback(Feedback&& f)
{
	this->writer = f.writer;
	this->date = f.date;
	this->content = f.content;
	f.writer = f.content = nullptr;
}

void Feedback::setDate(int day, int month, int year)
{
	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);
}

void Feedback::printFeedback()
{
	cout << this;
}

ostream& operator<<(ostream& os, const Feedback& feedback)
{
	os << "written by: " << feedback.writer << " on " << feedback.date << "\n" << feedback.content << "\n";
	return os;
}