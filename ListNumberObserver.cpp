//
// Created by daiji on 25/07/2023.
//

#include <iostream>
#include "ListNumberObserver.h"

ListNumberObserver::ListNumberObserver(ShoppingListManager *s) : subject(s), listnumber(0){
    subject->subscribe(this);
}

void ListNumberObserver::update() {
    listnumber= subject->getListNumber();
}

void ListNumberObserver::printalllists() {
    update();
    std::cout<<"printing my all lists"<<std::endl;
    subject->printLists();
    std::cout<<"ci sono "<<listnumber<<" liste."<<std::endl;
}
