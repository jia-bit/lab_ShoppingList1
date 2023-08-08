//
// Created by daiji on 25/07/2023.
//

#include <iostream>
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

float ShoppingList::gettotal() const {
    return this->total;
}

void ShoppingList::calcoltotal() {
    float result=0;
    for(auto itr:list){
        result=itr.getunitprice()*itr.getquantity()+result;
    }
    this->total=result;
}



void ShoppingList::modifysingleobjectquantity(const float& goalq, int pos) {
    if(pos>=0) {
        list.at(pos).setquantity(goalq);
        calcoltotal();
        notify();
    }
    if(goalq==0){
        removeobject(pos);
        calcoltotal();
    }
}

void ShoppingList::printlist() {
    int i=0;
    for(const auto itr:list){
        do{
            std::cout << i << ". oggetto: " << itr.getname() << "    -tipo: " << itr.gettype()
                      << "   -prezzo unitario: " << itr.getunitprice() << "  - quantita': "
                      << itr.getquantity() << "   -prezzo: " << itr.getprice() << std::endl;
            i++;
        }while(i<0);
    }
}


void ShoppingList::insertobject(const Object &value) {
    list.push_back(value);
    calcoltotal();

    notify();
    std::cout<<"inserimento oggetto successo"<<std::endl;
}

void ShoppingList::removeobject(int pos) {
    if(gettotal()!=0) {
        if (pos >= 0 && pos < list.size()) {
            list.erase(list.begin() + pos);
            calcoltotal();

            notify();
        }
    }else{
        std::cout<<"nessun oggetto da cancellare"<<std::endl;
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

std::string ShoppingList::getlistname() const {
    return this->listname;
}

ShoppingList::~ShoppingList() {
    list.clear();
}

void ShoppingList::renamelistname(const std::string &name) {
    this->listname=name;
}

const ShoppingList *ShoppingList::getlist() const {
    return this;
}


