#ifndef __BUYERSELLER_H
#define __BUYERSELLER_H
#include<iostream>
using namespace std;
#include "Seller.h"
#include "Buyer.h"
#include "User.h"

//class Seller;
//class Buyer;

class BuyerSeller: public Seller,public Buyer
{
public:
	BuyerSeller(const char* name,int password,Address* address);
	~BuyerSeller();
	BuyerSeller(const BuyerSeller& other) = delete;
	const BuyerSeller& operator=(const BuyerSeller& other) = delete;
	
	void show() const override
	{
		Buyer::show();
		Seller::show();
		cout << "This user is a buyer-seller" << endl;
	}
};

#endif // !__BUYERSELLER_H
