#ifndef __BUYER_H
#define __BUYER_H

#pragma warning (disable:4996)
#include<iostream>
using namespace std;
#include <string.h>

#include "User.h"
#include "Order.h"
#include "Product.h"
#include "Seller.h"
#include "Address.h"

//class User;
//class Seller;
//class Product;
//class Order;


class Buyer : virtual public User
{
protected:
	int sizeCart;
	int pSizeCart;
	Product** cart;
	int sizeOrder;
	int pSizeOrder;
	Order** orderArr;
	double sumCart;

public:
	Buyer(const char* name, int password, Address* address);
	virtual ~Buyer();
	Buyer(const Buyer& other) = delete;
	const Buyer& operator=(const Buyer& other) = delete;

	void show() const override;

	bool checkOrderFromSeller(const Seller* seller);
	bool checkDuplicateInCart(int serialNumber);
	void addProductToCart(Product* product);
	int getSizeProducts() const { return sizeCart; }
	int getSizeOrder() const { return sizeOrder; }
	void printCart() const;
	Product* getProductBySerialNumberAtBuyerCart(int serialNumber);
	void removeProductFromCart(Product* product);
	void addNewOrderToBuyer(Order* order);
	void payNextOrder();
	void printOrders() const;
	double getSumCart() const {return sumCart; }
	
	bool operator>(const Buyer& other) const;
};

#endif // !__BUYER_H
