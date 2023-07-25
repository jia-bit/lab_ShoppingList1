//
// Created by daiji on 25/07/2023.
//

#include <iostream>
#include "ShoppingListObserver.h"

ShoppingListObserver::ShoppingListObserver(ShoppingList *s) : subject(s), total(0){
    subject->subscribe(this);
}

void ShoppingListObserver::update() {
    subject->calcoltotal();
    total=subject->gettotal();
}

void ShoppingListObserver::printalist() {
    update();
    std::cout<<"Printing list: "<<subject->getlistname()<<std::endl;
    subject->printlist();
    std::cout<<"Totale della lista e': "<<total<<std::endl;
}

ShoppingListObserver::~ShoppingListObserver() {
    subject->unsubscribe(this);
}
