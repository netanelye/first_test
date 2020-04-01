#include "Seller.h"

Seller::Seller(const char* name, int password, Address* address) :User(name, password, address)
{
	this->sizeProducts = 0;
	this->pSizeProducts = 2;
	this->pArr = new Product * [pSizeProducts];
	this->sizeFeedback = 0;
	this->pSizeFeedback = 2;
	this->fArr = new Feedback * [pSizeFeedback];
}

Seller::~Seller()
{
	if (sizeProducts > 0)
		delete[]pArr;
	if (sizeFeedback > 0)
		delete[]fArr;
}

void Seller::addProductToSeller(Product* p)
{
	sizeProducts++;
	if (sizeProducts == pSizeProducts)
	{
		pSizeProducts *= 2;
		Product** tempArr = new Product *[pSizeProducts];
		for (int i = 0; i < sizeProducts - 1; i++)
		{
			tempArr[i] = pArr[i];
		}
		delete[] pArr;
		this->pArr = tempArr;
	}

	pArr[sizeProducts - 1] = p;
}

void Seller::addFeedbackToSeller(Feedback* f)
{
	sizeFeedback++;
	if (sizeFeedback == pSizeFeedback)
	{
		pSizeFeedback *= 2;
		Feedback** tempArr = new Feedback * [pSizeFeedback];
		for (int i = 0; i < sizeFeedback - 1; i++)
		{
			tempArr[i] = fArr[i];
		}
		delete[] fArr;
		this->fArr = tempArr;
	}
	fArr[sizeFeedback - 1] = f;
}

Product* Seller::getProductBySerialNumberAtSeller(int serialNumber)
{
	for (int i = 0; i < sizeProducts; i++)
	{
		if (this->pArr[i]->getSerialNumber() == serialNumber)
		{
			return pArr[i];
		}
	}

	return NULL;
}

void Seller::show() const
{
	User::show();
	cout << "This user is a seller" << endl;
	if (sizeProducts > 0)
	{
		cout << "Products: \n";
		for (int i = 0; i < sizeProducts; i++)
		{
			pArr[i]->printProduct();
		}
	}
	else cout << "Seller has no products to sell" << endl;
	if (sizeFeedback > 0)
	{
		cout << "\nSeller has been feedbacked" << endl;
		for (int i = 0; i < sizeFeedback; i++)
		{
			cout << "# " << i + 1 << endl;
			cout << *fArr[i];
		}
	}
	else cout << "Seller has no feedbacks" << endl;
}

void Seller::printProductsByNameAtSeller(char* ProductName)
{
	for (int i = 0; i < sizeProducts; i++)
	{
		if (strcmp(pArr[i]->getName(), ProductName) == 0)
			pArr[i]->printProduct();
	}
}