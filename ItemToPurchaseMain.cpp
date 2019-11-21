#include <iostream>
#include "ItemToPurchase.h"
#include <vector>
#include <iomanip>


using namespace std;

float totalPrice(vector<ItemToPurchase> list)
{
    int listSize = list.size(), i = 0;
    float totalC = 0;
    while (i < listSize)
    {
        totalC += (list.at(i).getPrice()) * list.at(i).getQuantity();
        i++;
    }

    return totalC;
}

int main()
{
    cout << fixed << setprecision(2);
    vector<ItemToPurchase> shoppingList(2);
    string name;
    int i = 0, listSize = shoppingList.size(), qty;

    float price, total;

    while (i < listSize)
    {
        cout << "Enter the item name:\n";
        getline(cin, name);

        cout << "Enter the item price:\n";
        cin >> price;

        cout << "Enter the item quantity:\n";
        cin >> qty;

        cin.ignore();
        cout << endl;

        shoppingList.at(i).setName(name);
        shoppingList.at(i).setPrice(price);
        shoppingList.at(i).setQuantity(qty);

        i++;
    }

    shoppingList.at(0).printItemCost();
    shoppingList.at(1).printItemCost();
    cout << endl;

    total = totalPrice(shoppingList);

    cout <<"Total: $" << total;

    return 0;
}
