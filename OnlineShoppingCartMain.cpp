#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    string customerName,
           item;
    float itemPrice;
    vector<ItemToPurchase> list(3);
    int i = 0, listSize = list.size(), itemQty;

    cout << "Name:  ";
    getline(cin, customerName);

    cout << endl;

    ShoppingCart newCart(customerName);

    while (i < listSize)
    {
        cout << "Enter the item name:\n";
        getline(cin, item);

        cout << "Enter the item price:\n";
        cin >> itemPrice;

        cout << "Enter the item quantity:\n";
        cin >> itemQty;

        cout << endl;

        cin.ignore();

        list.at(i).setName(item);
        list.at(i).setPrice(itemPrice);
        list.at(i).setQuantity(itemQty);

        newCart.addItem(list.at(i));

        i++;
    }

    newCart.printCart();
    cout << endl << "Total: $" << newCart.getTotalCost();

    return 0;
}
