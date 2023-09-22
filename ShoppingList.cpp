//
// Created by daiji on 25/07/2023.
//

#include <iostream>
#include <cmath>
#include "ShoppingList.h"

ShoppingList::ShoppingList(const std::string& n){
    total=0;
    listname=n;

}

ShoppingList::ShoppingList():total(0) {}

void ShoppingList::notify() {
    for(auto &itr:observers)
        itr->update();
}

void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}

float ShoppingList::getTotal() const {
    return this->total;
}

void ShoppingList::calculateTotal() {
    float result=0;
    for(auto &itr:list){
        if(!itr.isBought()) {
            result = itr.getUnitPrice() * itr.getQuantity() + result;
        }
    }
    result = std::round(result * 100) / 100;
    this->total=result;
}



void ShoppingList::modifyObjectQuantity(int goalq, int pos) {
    if(pos>=0) {
        list[pos].setQuantity(goalq);
        list[pos].setPrice();
        calculateTotal();
        notify();
    }
    if(goalq==0){
        removeObject(pos);
        calculateTotal();
    }
}

void ShoppingList::printList() const {
    for(int i=0; i<list.size(); i++){
        std::cout << i << ". oggetto: " << list[i].getName() << "    -tipo: " << list[i].getType()
                  << "   -prezzo unitario: " << list[i].getUnitPrice() << "  - quantita': "
                  << list[i].getQuantity() << "   -prezzo: " << list[i].getPrice() << std::endl;

    }
}


void ShoppingList::insertObject(const Object &value) {
    list.push_back(value);
    calculateTotal();
    notify();
    std::cout<<"inserimento oggetto successo"<<std::endl;
}

void ShoppingList::removeObject(int pos) {
    if(getTotal() != 0) {
        if (pos >= 0 && pos < list.size()) {
            list.erase(list.begin() + pos);
            calculateTotal();
            notify();
        }
    }else{
        std::cout<<"nessun oggetto da cancellare"<<std::endl; //togliere
    }

}

std::string ShoppingList::getName() const{
    return this->listname;
}

ShoppingList::~ShoppingList() {
    list.clear();
}

void ShoppingList::renameList(const std::string &name) {
    this->listname=name;
}

const ShoppingList *ShoppingList::getList() const {
    return this;
}

int ShoppingList::getnumberBought() const {
    int count=0;
    for(auto &itr:list){
        if(itr.isBought()){
            count++;
        }
    }
    return count;
}

void ShoppingList::setObjectbeBought(int pos) {
    if(pos>=0 && pos<list.size()) {
        if(!list[pos].isBought()){
            list[pos].setbeBought(true);
        }else{
            list[pos].setbeBought(false);
        }
    }
}


