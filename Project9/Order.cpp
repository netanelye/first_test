#include "Order.h"

Order::Order()
{
	totalPrice = 0;
	pSizeProduct = 2;
	sizeProduct = 0;
	productsOfOrder = new Product * [pSizeProduct];
	paid = false;
}

Order::Order(const Order& order)
{
	this->totalPrice = order.totalPrice;
	this->pSizeProduct = order.pSizeProduct;
	this->sizeProduct = order.sizeProduct;
	productsOfOrder = new Product * [pSizeProduct];
	Product* prod;
	for (int i = 0; i < sizeProduct; i++)
	{
		prod = order.productsOfOrder[i];
		productsOfOrder[i] = prod;
	}
	this->paid = order.paid;
}


Order::Order(Order&& order)
{
	this->pSizeProduct = order.pSizeProduct;
	this->sizeProduct = order.sizeProduct;
	this->productsOfOrder = order.productsOfOrder;
	this->totalPrice = order.totalPrice;
	this->paid = order.paid;
}

Order::~Order()
{
	delete[]productsOfOrder;
}

void Order::addToPrice(double price)
{
	this->totalPrice += price;
}

void Order::update(Product** arr)
{
	this->productsOfOrder = arr;
}

void Order::addProductToOrder(Product* product)
{
	this->totalPrice += product->getPrice();
	this->sizeProduct++;
	if (sizeProduct == pSizeProduct)
	{
		pSizeProduct *= 2;
		Product** tempArr = new Product * [pSizeProduct];
		for (int i = 0; i < sizeProduct - 1; i++)
		{
			tempArr[i] = this->productsOfOrder[i];
		}
		delete[] productsOfOrder;
		this->productsOfOrder = tempArr;
	}

	productsOfOrder[sizeProduct - 1] = product;

}

void Order::setOrder(Order* o)
{
	this->sizeProduct = o->sizeProduct;
	this->productsOfOrder = o->productsOfOrder;
	this->totalPrice = o->totalPrice;
	this->paid = o->paid;
}

double Order::getTotalPrice() const
{
	return totalPrice;
}

void Order::printOrder()
{
	cout << "** This is a summary of your order **" << endl;
	for (int i = 0; i < sizeProduct; i++)
	{
		productsOfOrder[i]->printProduct();
		cout << endl;
	}
	cout << "Total price is: " << totalPrice << endl;
	if (wasOrderPaid() == true)
	{
		cout << "Order was paid.\n";
	}
	else
	{
		cout << "Order was not paid yet..\n";
	}
}

bool Order::wasOrderPaid()
{
	return paid;
}

void Order::setOrderPaid()
{
	paid = true;
}

int Order::getProductsArrSize() const
{
	return sizeProduct;
}

bool Order::checkSellerInProductArr(const Seller* seller)
{
	for (int i = 0; i < sizeProduct; i++)
		if (productsOfOrder[i]->getSeller() == seller)
			return true;
	return false;
}

