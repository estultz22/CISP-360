#include "ItemToPurchase.h"
#include <iostream>

using std::string;

//default constructor
ItemToPurchase::ItemToPurchase()
{
    this->itemName = "none";
    this->itemPrice = 0.0f;
    this->itemQty = 0;
}

//parameterized constructor
ItemToPurchase::ItemToPurchase(string name, double price, int quantity)
{
    this->itemName = name;
    this->itemPrice = price;
    this->itemQty = quantity;
}


//mutators
void ItemToPurchase::setName(string itemName)
{
    this->itemName = itemName;
}

void ItemToPurchase::setPrice(double itemPrice)
{
    this->itemPrice = itemPrice;
}

void ItemToPurchase::setQuantity(int itemQty)
{
    this->itemQty = itemQty;
}

//accessors
string ItemToPurchase::getName() const
{
    return this->itemName;
}

double ItemToPurchase::getPrice() const
{
    return this->itemPrice;
}

int ItemToPurchase::getQuantity() const
{
    return this->itemQty;
}

void ItemToPurchase::printItemCost()
{
    std::cout << this->itemName << " " << this->itemQty << " @ $" << this->itemPrice <<
         " = $" << itemQty * itemPrice << std::endl;
}
