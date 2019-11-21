#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <string>
#include <vector>

class ShoppingCart
{
    public:
        ShoppingCart();//done
        ShoppingCart(std::string name);//done
        std::string getCustomerName() const;//done
        void addItem(ItemToPurchase);//done
        void removeItem(std::string);//done
        void changeQuantity(std::string, int);//done
        double getTotalCost();
        void printCart();//done

    private:
        std::string customerName;
        std::vector<ItemToPurchase> cartItems;
};

#endif // SHOPPINGCART_H
