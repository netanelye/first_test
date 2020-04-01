#include "Product.h"


Product::Product(char* name, double price, eCategory category, Seller* seller)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->price = price;
	this->serialNumber = ++staticSerialNumer;
	this->category = category;
	this->seller = seller;
}

Product::Product(const Product& p)
{
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name, p.name);
	this->price = p.price;
	this->serialNumber = p.serialNumber;
	this->category = p.category;
	this->seller = p.seller;

}

Product::Product(Product&& p)
{
	this->name = p.name;
	this->price = p.price;
	this->serialNumber = p.serialNumber;
	this->category = p.category;
	this->seller = p.seller;
	p.name = nullptr;
}

Product::~Product()
{
	if (name != nullptr)
		delete[]name;
}

void Product::setProduct(Product& p)
{
	this->price = p.price;
	this->serialNumber = p.serialNumber;
	this->category = p.category;
	this->seller = p.seller;
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name, p.name);
}

int Product::getSerialNumber() const
{
	return serialNumber;
}

void Product::printProduct()
{
	cout << "Seller is: " << seller->getName() << " Category: " << categoryArr[(int)category] << ", name: " << name << ", price: " << price << ", serial number: " << serialNumber << endl;
}

char* Product::getName() const
{
	return name;
}

double Product::getPrice() const
{
	return price;
}

void Product::setSerialNumber(int serialNumber)
{
	this->serialNumber = serialNumber;
}


int Product::staticSerialNumer;

ostream& operator<<(ostream& os, const Product& p)
{
	os << "Seller is: " << p.seller->getName() << " Category: " << categoryArr[(int)p.category] << ", name: " << p.name << ", price: " << p.price << ", serial number: " << p.serialNumber << endl;
	return os;
}