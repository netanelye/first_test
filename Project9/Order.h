#ifndef __ORDER_H
#define __ORDER_H

#pragma warning (disable:4996)
#include <iostream>
using namespace std;
#include <string.h>

#include "Product.h"

class Order
{
public:
	Order();
	Order(const Order& order);
	Order(Order&& order);
	~Order();
private:
	int pSizeProduct;
	int sizeProduct;
	Product** productsOfOrder;
	double totalPrice;
	bool paid;
public:
	void addToPrice(double price);
	void update(Product** arr);
	void addProductToOrder(Product* product);
	void printOrder();
	double getTotalPrice() const;
	bool wasOrderPaid();
	void setOrderPaid();
	void setOrder(Order* o);
	int getProductsArrSize() const;
	bool checkSellerInProductArr(const Seller* seller);
};

#endif // !__ORDER_H
