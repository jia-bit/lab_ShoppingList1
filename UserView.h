//
// Created by daiji on 25/07/2023.
//

#ifndef LAB_SHOPPINGLIST1_USERVIEW_H
#define LAB_SHOPPINGLIST1_USERVIEW_H


#include "ShoppingListManager.h"

class UserView {
public:
    explicit UserView(ShoppingListManager* ls);

    void Menu();
    void Displayinlist();

private:
    ShoppingListManager* lists;
};


#endif //LAB_SHOPPINGLIST1_USERVIEW_H
