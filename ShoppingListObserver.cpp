//
// Created by daiji on 25/07/2023.
//

#include <iostream>
#include "ShoppingListObserver.h"

ShoppingListObserver::ShoppingListObserver(ShoppingList *s) : subject(s), total(0){
    subject->subscribe(this);
}

void ShoppingListObserver::update() {
    subject->calculateTotal();
    total= subject->getTotal();
}


ShoppingListObserver::~ShoppingListObserver() {
    subject->unsubscribe(this);
}
