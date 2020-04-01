#include "System.h"

System::System(const char* _systemName)
{
	systemName = _systemName;
	sizeUser = 0;
	pSizeUser = 2;
	arrUser = new User * [pSizeUser];
	numOfSellers = 0;
	numOfBuyers = 0;
	numOfBuyersSellers = 0;
}

System::~System()
{
	for (int i = 0; i < sizeUser; i++)
	{
		delete arrUser[i];
	}
	delete[]arrUser;
}

void System::printManu()
{
	cout << "1: add a buyer\n";
	cout << "2: add a seller\n";
	cout << "3: add a buyer-seller\n";
	cout << "4: add a product to seller\n";
	cout << "5: add feedback to seller\n";
	cout << "6: add a product to a buyer cart\n";
	cout << "7: make an order for buyer\n";
	cout << "8: order payment for buyer\n";
	cout << "9: show all buyers\n";
	cout << "10: show all sellers\n";
	cout << "11: show all buyers-sellers\n";
	cout << "12: show all product with a specific name\n";
	cout << "13: compare between 2 buyers\n";
	cout << "14: exit\n\n";

	cout << "Please choose one of the options above: ";
}

void System::cleanBuffer()
{
	int c;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');
}

void System::addBuyerToArr(Buyer* buyer)
{
	allocateArray();
	arrUser[sizeUser - 1] = buyer;
}

bool System::checkDupName(char* name)
{
	for (int i = 0; i < sizeUser; i++)
	{
		if (strcmp(name, arrUser[i]->getName()) == 0)
			return true;
	}

	return false;
}

Address* System::addAddress()
{
	char street[MAX_LENGTH];
	int house;
	char country[MAX_LENGTH];
	char city[MAX_LENGTH];
	Address* address;

	cout << "Please enter your address: \n";
	cout << "Street: ";
	cleanBuffer();
	cin.getline(street, MAX_LENGTH);
	cout << "Home number: ";
	cin >> house;
	cout << "City: ";
	cleanBuffer();
	cin.getline(city, MAX_LENGTH);
	cout << "Country: ";
	//cleanBuffer();
	cin.getline(country, MAX_LENGTH);
	address = new Address(country, city, street, house);
	return address;
}


void System::allocateArray()
{
	sizeUser++;
	if (sizeUser == pSizeUser)
	{
		pSizeUser *= 2;
		User** tempArr = new User * [pSizeUser];
		for (int i = 0; i < sizeUser - 1; i++)
		{
			tempArr[i] = this->arrUser[i];
		}
		delete[] arrUser;
		this->arrUser = tempArr;
	}
}

void System::addProduct()
{
	char sellerName[MAX_LENGTH];
	char productName[MAX_LENGTH];
	User* user;

	double price;
	int temp;
	eCategory category;

	cout << "Enter the seller name: \n";
	cleanBuffer();
	cin.getline(sellerName, MAX_LENGTH);
	user = getUserByName(sellerName);
	Seller* seller = dynamic_cast<Seller*>(user);

	if (user != NULL && seller)
	{
		cout << "\nEnter a product" << endl;
		cout << "Name: ";
		cin.getline(productName, 20);
		cout << "Price: ";
		cin >> price;
		while (price < 0)
		{
			cout << "price can't be a negative number, please try again" << endl;
			cin >> price;
		}
		cout << "Choose category:\nChildren - 0\nElectricity - 1\nOffice - 2\nClothing - 3" << endl;
		cout << "Enter your choice: ";
		cin >> temp;
		category = (eCategory)temp;

		Product* product = new Product(productName, price, category, seller);
		seller->addProductToSeller(product);
		cout << *product << endl;
		cout << "Product added successfully to seller store :)" << endl;
	}

	else cout << "There is no such a seller " << sellerName << "!!! Back to menu \n";
}

User* System::getUserByName(const char* name) const
{
	for (int i = 0; i < sizeUser; i++)
	{
		if (strcmp(arrUser[i]->getName(), name) == 0)
			return arrUser[i];
	}
	return NULL;
}

void System::addFeedback()
{
	int d, m, y;
	char content[251];
	char buyerName[MAX_LENGTH];
	char sellerName[MAX_LENGTH];
	Feedback* newFback;
	User* user;

	cout << "enter buyer name: ";//input - buyer name
	cleanBuffer();
	cin.getline(buyerName, MAX_LENGTH);
	user = getUserByName(buyerName);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	if (user != NULL && buyer) //check if customer exists
	{
		cout << "enter seller name to feedback: ";
		cin.getline(sellerName, MAX_LENGTH);//input - seller to feedback
		user = getUserByName(sellerName);
		Seller* seller = dynamic_cast<Seller*>(user);
		if (user != NULL && seller) // check if seller even exists
		{
			if (!(buyer->checkOrderFromSeller(seller)))
			{
				cout << "You didn't make a purchase from " << sellerName << endl;
				cout << "Please notice that you must pay for your order before feedbacking.\nBack to manu." << endl;
			}
			else
			{
				cout << "please enter your feedback (up to 250 letters):" << endl;
				cin.getline(content, 250);
				cout << "Please enter date" << endl;
				cout << "day (DD format): ";
				cin >> d;
				cout << "month (MM format): ";
				cin >> m;
				cout << "year (YYYY format): ";
				cin >> y;
				while (d < 0 || d>30 || m > 12 || m < 0 || y>2021 || y < 1900)
				{
					cout << "please put the correct date\n";
					cin >> d >> m >> y;
				}
				Date date(d, m, y);
				newFback = new Feedback(buyerName, date, content);
				seller->addFeedbackToSeller(newFback);
				cout << "Feedback added successfully :)" << endl;
			}

		}
		else
		{
			cout << "seller not found. back to manu" << endl;

		}
	}
	else cout << "Buyer not found. back to manu" << endl;

}

void System::addProductToCart()
{
	char buyerName[MAX_LENGTH];
	int serialNumber;

	cout << "Enter the buyer name: \n";
	cleanBuffer();
	cin.getline(buyerName, MAX_LENGTH);
	User* user = getUserByName(buyerName);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	if (user != NULL && buyer)
	{
		cout << "Enter serial number of product: \n";
		cin >> serialNumber;
		if (buyer->checkDuplicateInCart(serialNumber) == true)
		{
			cout << "You have already added this product to your cart! back to manu" << endl;
		}
		else
		{
			Product* p = getProductBySerialNumber(serialNumber);
			if (p != NULL)
			{
				if (strcmp(p->getSeller()->getName(), buyerName) == 0)
				{
					cout << "You can't buy a product that you sell\nBack to manu" << endl;
				}
				else
				{
					buyer->addProductToCart(p);
					cout << "Product added successfully to buyer cart." << endl;
				}
			}
			else cout << "There is no such a product with the serial number " << serialNumber << " !!! Back to menu \n";
		}
	}
	else cout << "There is no such a buyer " << buyerName << " !!! Back to menu \n";
}

Product* System::getProductBySerialNumber(int serialNumber)
{
	Product* p = NULL;
	Seller* s;
	for (int i = 0; i < sizeUser; i++)
	{
		s = dynamic_cast<Seller*>(arrUser[i]);
		if (s)
		{
			p = s->getProductBySerialNumberAtSeller(serialNumber);
			if (p != NULL)
				return p;
		}
	}

	return p;
}

void System::makeOrder()
{
	char buyerName[MAX_LENGTH];
	int serialNumber;

	cout << "Enter name of buyer: \n";
	cleanBuffer();
	cin.getline(buyerName, MAX_LENGTH);
	User* user = getUserByName(buyerName);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	if (user != NULL && buyer)
	{

		if (buyer->getSizeProducts() != 0)
		{
			buyer->printCart();
			cout << endl;

			Order* o = new Order;
			Product* p;

			int flag = 1;
			while (flag == 1)
			{
				cout << "Enter the serial number of the product: \n";
				cin >> serialNumber;
				p = buyer->getProductBySerialNumberAtBuyerCart(serialNumber);
				if (p != NULL)
				{
					o->addProductToOrder(p);
					buyer->removeProductFromCart(p);
				}
				else
				{
					cout << "There is no such a product at this cart with the serial number " << serialNumber << endl;
				}
				cout << "Enter 1 to add another product, 0 to finish :\n";
				cin >> flag;
			}
			buyer->addNewOrderToBuyer(o);
			cout << "Your order has been placed successfully :)" << endl;
			o->printOrder();
		}
		else cout << "Cart is empty !!! back to menu \n";
	}
	else cout << "There is no buyer " << buyerName << endl;
}

void System::payOrder()
{
	char buyerName[MAX_LENGTH];
	cout << "Enter name of buyer: \n";
	cleanBuffer();
	cin.getline(buyerName, MAX_LENGTH);
	User* user = getUserByName(buyerName);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	if (user != NULL && buyer)
	{
		if (buyer->getSizeOrder() != 0)
		{
			buyer->payNextOrder();
		}
		else cout << "There is no order !!! back to menu\n";
	}
	else cout << "There is no buyer " << buyerName << endl;
}

void System::printProductsByName(char* ProductName)
{
	Seller* seller;
	for (int i = 0; i < sizeUser; i++)
	{
		seller = dynamic_cast<Seller*>(arrUser[i]);
		if (seller)
		{
			seller->printProductsByNameAtSeller(ProductName);
		}
	}
}

/*void System:: operator+=(const Buyer& other)
{
	allocateArray();
	arrUser[sizeUser - 1] = other;
	numOfBuyers++;
}*/

/*void System::operator+=(const Seller& other)
{
	allocateArray();
	arrUser[sizeUser - 1] = other;
	numOfBuyers++;
}*/
