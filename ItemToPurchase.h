#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>

class ItemToPurchase
{
    public:
        ItemToPurchase();//done
        ItemToPurchase(std::string name, double price, int quantity);//done
        void setName(std::string itemName);//done
        void setPrice(double itemPrice);//done
        void setQuantity(int itemQty);//done
        std::string getName() const;//done
        double getPrice() const;//done
        int getQuantity() const;//done
        void printItemCost();

    private:
        std::string itemName;
        double itemPrice;
        int itemQty;
};

#endif // ITEMTOPURCHASE_H
