#pragma once
#ifndef __SELLER_H
#define __SEELER_H

#pragma warning (disable:4996)
#include<iostream>
using namespace std;

#include "Feedback.h"
#include "User.h"
#include "Product.h"

class Product;


class Seller : virtual public User
{
protected:
	int pSizeProducts;
	int sizeProducts;
	Product** pArr;
	int sizeFeedback;
	int pSizeFeedback;
	Feedback** fArr;
public:
	Seller(const char* name, int password, Address* address);
	virtual ~Seller();
	
	void show() const override;

	void addProductToSeller(Product* p);
	void addFeedbackToSeller(Feedback* f);

	const Seller& operator=(const Seller& other) = delete;
	Seller(const Seller& other) = delete;
	Product* getProductBySerialNumberAtSeller(int serialNumber);
	void printProductsByNameAtSeller(char* ProductName);
};

#endif // !__SELLER_H
