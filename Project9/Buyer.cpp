#include "Buyer.h"

Buyer::Buyer(const char* name, int password, Address* address) :User(name, password, address)
{
	this->pSizeCart = 2;
	this->sizeCart = 0;
	this->cart = new Product * [pSizeCart];
	this->sizeOrder = 0;
	this->pSizeOrder = 2;
	this->orderArr = new Order * [pSizeOrder];
	sumCart = 0;
}

Buyer::~Buyer()
{

	delete[]cart;
	delete[]orderArr;
}

bool Buyer::checkOrderFromSeller(const Seller* seller)
{
	for (int i = 0; i < sizeOrder; i++)
	{
		if (orderArr[i]->checkSellerInProductArr(seller))
		{
			if (orderArr[i]->wasOrderPaid())
				return true;
		}
	}
	return false;
}

bool Buyer::checkDuplicateInCart(int serialNumber)
{
	for (int i = 0; i < sizeCart; i++)
	{
		if (cart[i]->getSerialNumber() == serialNumber)
			return true;
	}
	return false;
}

void Buyer::addProductToCart(Product* p)
{
	sizeCart++;
	if (sizeCart == pSizeCart)
	{
		pSizeCart *= 2;
		Product** tempArr = new Product * [pSizeCart];
		for (int i = 0; i < sizeCart - 1; i++)
		{
			tempArr[i] = this->cart[i];
		}
		delete[] cart;
		this->cart = tempArr;
	}

	cart[sizeCart - 1] = p;
	sumCart += p->getPrice();
}

void Buyer::printCart() const
{
	if (sizeCart > 0)
	{
		cout << "Your cart is: \n";
		for (int i = 0; i < sizeCart; i++)
		{
			cart[i]->printProduct();
			cout << endl;
		}
	}

	else cout << "Cart is empty" << endl;
}

Product* Buyer::getProductBySerialNumberAtBuyerCart(int serialNumber)
{
	for (int i = 0; i < sizeCart; i++)
	{
		if (cart[i]->getSerialNumber() == serialNumber)
			return cart[i];
	}
	return NULL;
}

void Buyer::removeProductFromCart(Product* product)
{
	Product** tempArr = new Product * [pSizeCart];
	int j = 0;
	for (int i = 0; i < sizeCart; i++)
	{
		if (this->cart[i]->getSerialNumber() != product->getSerialNumber())
		{
			tempArr[j] = cart[i];
			j++;
		}
	}
	sizeCart--;
	delete[]cart;
	this->cart = tempArr;
	sumCart -= product->getPrice();
}

void Buyer::addNewOrderToBuyer(Order* order)
{
	sizeOrder++;
	if (sizeOrder == pSizeOrder)
	{
		Order** tempArr = new Order * [pSizeOrder];
		for (int i = 0; i < sizeOrder - 1; i++)
		{
			tempArr[i] = orderArr[i];
		}
		delete[]orderArr;
		this->orderArr = tempArr;
	}
	orderArr[sizeOrder - 1] = order;
}

void Buyer::payNextOrder()
{
	int flag = 1;
	for (int i = 0; flag && i < sizeOrder; i++)
	{
		if (orderArr[i]->wasOrderPaid() == false)
		{
			orderArr[i]->printOrder();
			orderArr[i]->setOrderPaid();
			cout << "Order was paid successfully :)\n";
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "All orders were alreay paid.\n";
	}
}

void Buyer::show() const
{
	User::show();
	cout << "This user is a buyer" << endl;
	this->printCart();
	this->printOrders();
}

void Buyer::printOrders() const
{
	if (sizeOrder > 0)
	{
		for (int i = 0; i < sizeOrder; i++)
		{
			orderArr[i]->printOrder();
			cout << endl;
		}
	}
	else cout << "There are no orders" << endl;
}

bool Buyer::operator>(const Buyer& other) const
{
	return (this->getSumCart() > other.getSumCart());
}
