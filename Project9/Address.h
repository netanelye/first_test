#ifndef __ADDRESS_H
#define __ADDRESS_H

#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

class Address
{
private:
	char* country;
	char* city;
	char* street;
	int house;
public:
	Address() = default;
	Address(char* country, char* city, char* street, int house);
	Address(const Address& add);
	~Address();
	const Address& operator=(const Address& other);

	void printAddress();
};

#endif // !__ADDRESS_H
