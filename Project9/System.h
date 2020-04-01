#ifndef __SYSTEM_H
#define __SYSTEM_H

#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

#include "User.h"
#include "Product.h"
#include "Buyer.h"
#include "BuyerSeller.h"

const int MAX_LENGTH = 30;

class System
{
private:
	const char* systemName;
	User** arrUser;
	int sizeUser;
	int pSizeUser;
	int numOfSellers;
	int numOfBuyers;
	int numOfBuyersSellers;

public:
	System(const char* systemName);
	~System();
	System(const System& sys) = delete;
	const System& operator=(const System& other) = delete;

	void run();
	void printManu();
	void cleanBuffer();
	void addBuyerToArr(Buyer* buyer);
	bool checkDupName(char* name);
	Address* addAddress();
	void allocateArray();
	void addProduct();
	User* getUserByName(const char* name) const;
	void addFeedback();
	void addProductToCart();
	Product* getProductBySerialNumber(int serialNumber);
	void makeOrder();
	void payOrder();
	void printProductsByName(char* ProductName);
	
	void operator+=(const Buyer& other);
	void operator+=(const Seller& other);
};

#endif // !__SYSTEM_H