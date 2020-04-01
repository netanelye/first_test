#include "User.h"

User::User(const char* name, int password, Address* address):name(strdup(name)),password(password),address(address)
{
}

User::~User()
{
	if (name != nullptr)
		delete[]name;
}

/*User::User(const User& b)
{
	this->name = new char[strlen(b.name) + 1];
	strcpy(this->name, b.name);
	this->password = b.password;
	this->address = (b.address);
}

const User& User::operator=(const User& other)
{
	if (this != &other)
	{
		password = other.password;
		delete[] name;
		name = strdup(other.name);
		address = other.address;
	}

	return *this;
}*/

void User::show() const
{
	cout << "name: " << name << endl;
	address->printAddress();
}






