#ifndef __USER_H
#define __USER_H

#include "Address.h"

class User
{
protected:
	char* name;
	int password;
	Address* address;

public:
	User(const char* name, int password, Address* address);
	virtual ~User();
	const char* getName() const { return name; }
	virtual void show() const = 0;

	int getPassword() const { return password; }
	Address& getAddress() const { return *address; }

	User(const User& other) = delete;
	const User& operator=(const User& other) = delete;
};

#endif // !__USER_H