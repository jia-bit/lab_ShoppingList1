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

void ShoppingListManager::insertShoppinglist(ShoppingList *newlist) {
    bool listExists = false;
    if(getListNumber() != 0) {
        for (auto &itr: lists) {
            if (itr->getName() == newlist->getName()) {
                listExists = true;
                break;
            }
        }
    }
    if(listExists) {
        std::cout << "lista gia' esistente" << std::endl;
    }else{
        lists.push_back(newlist);
        setListNumber(1);
        notify();
        std::cout<<"inserimento shopping list successo"<<std::endl;
    }
}

void ShoppingListManager::deleteShoppinglist(int pos) {
    if(getListNumber() != 0 && pos >= 0 && pos < lists.size()) {
        delete lists[pos];
        lists.erase(lists.begin()+pos);
        setListNumber(-1);
        notify();
        std::cout<<"lista selezionata cancellata!"<<std::endl;
    }else {
        std::cout << "non c' e' lista da cancellare." << std::endl;
    }
}

void ShoppingListManager::printLists() {
    if(getListNumber() != 0) {
        std::cout<<"My all lists: "<<std::endl;
        for (int i=0; i<lists.size();i++) {
            std::cout << i << ". List Name: " << lists[i]->getName() << "   -total: " << lists[i]->getTotal() << std::endl;
        }
    }else{
        std::cout<<"non c' e' nessuna lista"<<std::endl;
    }
}

int ShoppingListManager::getListNumber() const {
    return this->listnumber;
}

void ShoppingListManager::setListNumber(int n) {
    listnumber+=n;
}


void ShoppingListManager::showOneList(const std::string &name) {
    for(auto &itr:lists) {
        if (itr->getName() == name) {
            itr->printList();
            break;
        }
    }
}


bool ShoppingListManager::renameList(const std::string &newname, const std::string& oldname) {
    bool oldNameFound = false;
    for (auto &itr: lists) {
        if (itr->getName() == oldname) {
            oldNameFound=true;
            if (itr->getName() == newname) {
                std::cout << "nome gia' esistente!" << std::endl;
                return false;
            }else {
                itr->renameList(newname);
                std::cout << "rinominata!" << std::endl;
                return true;
            }
        }
    }

    if(!oldNameFound){
        std::cout << "Lista non esistente" << std::endl;
        return false;
    }
}



void ShoppingListManager::insertnewObject(const std::string &name,const Object& obj) {
    for(auto &itr:lists){
        if(itr->getName() == name){
            itr->insertObject(obj);
        }else{
            std::cout<<"lista non riconosciuta"<<std::endl;
        }
    }
}

void ShoppingListManager::removeObject(const std::string& name, int pos) {
    for(auto &itr:lists) {
        if (itr->getName() == name) {
            itr->removeObject(pos);
        }
    }
}

void ShoppingListManager::modifyObjectQuantity(const std::string& name, int goalq, int pos) {
    for(auto &itr:lists) {
        if (itr->getName() == name) {
            itr->modifyObjectQuantity(goalq, pos);
        }
    }
}

bool ShoppingListManager::findList(const std::string &name) {
    for(const auto itr:lists){
        if(itr->getName() == name){
            return true;
        }
    }
    return false;
}

void ShoppingListManager::copyList(const std::string &name) {
    std::string Newname=name+"copied";
    for(auto &itr:lists){
        if(itr->getName() == name){
            ShoppingList copylist(*itr->getList());
            copylist.renameList(Newname);
            insertShoppinglist(new ShoppingList(copylist));;
            notify();
            std::cout<<"lista copiata!"<<std::endl;
            break;
        }
    }
}

void ShoppingListManager::setObjectbeBought(int pos, const std::string &name) {
    for(auto &itr:lists){
        if(itr->getName() == name){
            itr->setObjectbeBought(pos);
        }
    }
}
