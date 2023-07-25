//
// Created by daiji on 25/07/2023.
//

#include <iostream>
#include "ShoppingListManager.h"

ShoppingListManager::ShoppingListManager() {

    listnumber=0;
}


void ShoppingListManager::notify() {
    for(auto &itr:observers){
        itr->update();
    }
}

void ShoppingListManager::subscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingListManager::unsubscribe(Observer *o) {
    observers.remove(o);
}

void ShoppingListManager::insertShoppinglist(const ShoppingList& newlist) {
    lists.insert(std::pair(newlist.getlistname(), newlist));
    setlistnumber(1);
    notify();
    std::cout<<"inserimento shopping list successo"<<std::endl;
}

void ShoppingListManager::deleteShoppinglist(const std::string& listname) {
    if(getlistnumber()!=0) {
        auto itr = lists.find(listname);
        if (itr != lists.end()) {
            lists.erase(listname);
            setlistnumber(-1);
            notify();
        }
    }else {
        std::cout << "non c' e' lista da cancellare." << std::endl;
    }
}

void ShoppingListManager::printlists() {
    int i=1;
    std::cout<<"My all lists: "<<std::endl;
    for (const auto &itr: lists) {
        do{
            std::cout << i << " . " << "List Name: " << itr.first << "    - total of List: " << itr.second.gettotal() << std::endl;
            i++;
        }while(i<1);
    }
}

int ShoppingListManager::getlistnumber() const {
    return this->listnumber;
}

void ShoppingListManager::setlistnumber(int n) {
    listnumber+=n;
}

void ShoppingListManager::showonelist(const std::string &name) {
    for(auto itr:lists){
        if(itr.first==name){
            if(itr.second.gettotal()!=0) {
                itr.second.printlist();
            }else {
                std::cout<<"non c' e' nessun oggetto"<<std::endl;
            }
        }else{
            std::cout<<"lista non esiste!"<<std::endl;
            std::cout<<"riinserisci il nome della lista: "<<std::endl;
        }
    }
}

void ShoppingListManager::renamelist(const std::string &newname, const std::string &origilname) {
    for(auto itr:lists) {
        if(newname==itr.first){
            std::cout<<"nome della lista gia' esistente, riinserisci il nome: "<<std::endl;
        }
        if (itr.first == origilname) {
            itr.second.renamelistname(newname);
            std::cout<<"rinominata!"<<std::endl;
        }else{
            std::cout<<"rinominazione fallita!"<<std::endl;
        }
    }
}

void ShoppingListManager::removeobject(const std::string &name, int pos) {
    for(auto itr:lists) {
        if (itr.first == name) {
            itr.second.removeobject(pos);
        }
    }
}
