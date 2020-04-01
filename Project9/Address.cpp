#include "Address.h"

Address::Address(char* country, char* city, char* street, int house)
{
	this->country = new char[strlen(country) + 1];
	this->city = new char[strlen(city) + 1];
	this->street = new char[strlen(street) + 1];
	strcpy(this->country, country);
	strcpy(this->city, city);
	strcpy(this->street, street);
	this->house = house;
}

Address::Address(const Address& add)
{

	*this = add;
}

Address::~Address()
{
	if (country != nullptr)
		delete[]country;
	if (city != nullptr)
		delete[]city;
	if (street != nullptr)
		delete[]street;
}

void Address::printAddress()
{
	cout << "Address is: " << country << " " << city << " " << street << " " << house << endl;
}

const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		house = other.house;
		delete[] country;
		delete[] city;
		delete[] street;

		country = strdup(other.country);
		city = strdup(other.city);
		street = strdup(other.street);
	}

	return *this;
}