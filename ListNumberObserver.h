//
// Created by daiji on 25/07/2023.
//

#ifndef LAB_SHOPPINGLIST1_LISTNUMBEROBSERVER_H
#define LAB_SHOPPINGLIST1_LISTNUMBEROBSERVER_H


#include "Observer.h"
#include "ShoppingListManager.h"

class ListNumberObserver : public Observer{
public:
    ListNumberObserver(ShoppingListManager* s);
    void update() override;
    void printalllists();

private:
    ShoppingListManager* subject;
    int listnumber;

};


#endif //LAB_SHOPPINGLIST1_LISTNUMBEROBSERVER_H
