#include "ShoppingCart.h"
#include <vector>
#include <iostream>

using std::string;
using std::cout;

ShoppingCart::ShoppingCart()
{
    this->customerName = "none";
}

ShoppingCart::ShoppingCart(string name)
{
    this->customerName = name;
}

string ShoppingCart::getCustomerName() const
{
    return this->customerName;
}

double ShoppingCart::getTotalCost()
{
    double total = 0;
    int i = 0, listSize = cartItems.size();

    do
    {
        total += cartItems.at(i).getQuantity() * cartItems.at(i).getPrice();
        i++;
    }while (i < listSize);

    return total;
}

void ShoppingCart::addItem(ItemToPurchase newItem)
{
    this->cartItems.push_back(newItem);
}

void ShoppingCart::removeItem(string rmvItem)
{
    int i = 0, listSize = cartItems.size();
    bool found = false;

    string currItem;

    do
    {
        currItem = this->cartItems.at(i).getName();

        if (currItem == rmvItem)
        {
            cartItems.erase(cartItems.begin() + i);
            found = true;
        }
        i++;

    }while (currItem != rmvItem && i < listSize);

    if(!found)
    {
        cout << "Item not found in cart. Nothing removed.\n\n";
    }

}

void ShoppingCart::printCart()
{
    int i = 0, listSize = cartItems.size();
    cout << this->customerName << "'s Shopping Cart\n\n";

    while (i < listSize)
    {
        cartItems.at(i).printItemCost();
        i++;
    }
}

void ShoppingCart::changeQuantity(string item, int newQty)
{
    int i = 0, listSize = cartItems.size();
    bool found = false;

    string currItem;

    do
    {
        currItem = this->cartItems.at(i).getName();

        if (currItem == item)
        {
            cartItems.at(i).setQuantity(newQty);
            found = true;
        }

        i++;

    }while (currItem != item && i < listSize);

    if(!found)
    {
        cout << "Item not found in cart. Nothing modified.\n\n";
    }
}



