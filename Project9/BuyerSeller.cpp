#include "BuyerSeller.h"



BuyerSeller::BuyerSeller(const char* name, int password, Address* address) :User(name, password, address),Buyer(name, password, address),Seller(name, password, address)
{}


BuyerSeller::~BuyerSeller()
{
}
