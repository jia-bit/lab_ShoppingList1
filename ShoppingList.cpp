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
        if(!itr.getbeBought()) {
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

void ShoppingList::printList() {
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


ShoppingList::ShoppingList(const ShoppingList &orig) {
    total=orig.total;
    listname=orig.listname;
    if(!orig.list.empty()  && !orig.observers.empty()){
        list.resize(orig.list.size());
        for (const auto itr0:orig.list) {
            list.push_back(itr0);
        }


        for(const auto &itr: orig.observers){
            observers.push_back(itr);
        }

    }else{
        list.clear();

        observers.clear();
    }
}

ShoppingList &ShoppingList::operator=(const ShoppingList &right) {
    if(this!=&right){
        if(!list.empty() || !observers.empty()){
            list.clear();
            observers.clear();
        }

        total=right.total;
        listname=right.listname;
        if(!right.list.empty()  && !right.observers.empty()){
            list.resize(right.list.size());

            for (const auto itr0:right.list) {
                list.push_back(itr0);
            }


            for(const auto &itr: right.observers){
                observers.push_back(itr);
            }
        }
    }
    return *this;
}

std::string ShoppingList::getListName(){
    return this->listname;
}

ShoppingList::~ShoppingList() {
    list.clear();
}

void ShoppingList::renameListName(const std::string &name) {
    this->listname=name;
}

const ShoppingList *ShoppingList::getList() const {
    return this;
}

int ShoppingList::getnumberBoughtObject() {
    int count=0;
    for(auto &itr:list){
        if(itr.getbeBought()){
            count++;
        }
    }
    return count;
}

void ShoppingList::setObjectbeBought(int pos) {
    if(pos>=0 && pos<list.size()) {
        if(!list[pos].getbeBought()){
            list[pos].setbeBought(true);
        }else{
            list[pos].setbeBought(false);
        }
    }
}


