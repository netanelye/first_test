#ifndef __PRODUCT_H
#define __PRODUCT_H

#pragma warning (disable:4996)
#include <iostream>
using namespace std;

#include <string.h>

#include "Seller.h"
class Seller;

enum class eCategory { CHILDREN, ELECTRICITY, OFFICE, CLOTHING };
static const char* categoryArr[] = { "CHILDREN", "ELECTRICITY", "OFFICE", "CLOTHING" };

class Product
{
private:
	char* name;
	double price;
	int serialNumber;
	eCategory category;
	Seller* seller;
	static int staticSerialNumer;
public:
	Product() = default;
	Product(char* name, double price, eCategory category, Seller* seller = nullptr);
	Product(const Product& p);
	Product(Product&& p);
	~Product();
	int getSerialNumber() const;
	void printProduct();
	char* getName() const;
	double getPrice() const;
	void setProduct(Product& p);
	void setSerialNumber(int serialNumber);
	Seller* getSeller() const { return seller; }
	friend ostream& operator<<(ostream& os, const Product& p);
};

#endif // !__PRODUCT_H
