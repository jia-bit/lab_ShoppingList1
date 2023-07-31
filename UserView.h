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
    void printallLists();
    void Displayinlist();

    void showonelist(const ShoppingList* const list);
    void insertnewlist(ShoppingList* newlist);
    void renamelistname(const std::string& newname, const std::string& origlname);
    void removeobject( const std::string& name, int pos);

private:
    ShoppingListManager* lists;
};


#endif //LAB_SHOPPINGLIST1_USERVIEW_H
