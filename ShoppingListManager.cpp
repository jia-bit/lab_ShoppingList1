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
    if(getlistnumber()!=0) {
        for (auto &itr: lists) {
            if (itr->getlistname()== newlist->getlistname()) {
                listExists = true;
                break;
            }
        }
    }
    if(listExists) {
        std::cout << "lista gia' esistente" << std::endl;
    }else{
        lists.push_back(newlist);
        setlistnumber(1);
        notify();
        std::cout<<"inserimento shopping list successo"<<std::endl;
    }
}

void ShoppingListManager::deleteShoppinglist(int pos) {

    if(getlistnumber()!=0) {
        lists.erase(lists.begin()+pos);
        setlistnumber(-1);
        notify();
        std::cout<<"lista selezionata cancellata!"<<std::endl;
    }else {
        std::cout << "non c' e' lista da cancellare." << std::endl;
    }
}

void ShoppingListManager::printlists() {
    int i=0;
    if(getlistnumber()!=0) {
        std::cout<<"My all lists: "<<std::endl;
        for (const auto &itr: lists) {
            do {
                std::cout << i << " . " << "List Name: " << itr->getlistname() <<"    -totale: "<<itr->gettotal()<<std::endl;
                i++;
            } while (i < 0);
        }
    }else{
        std::cout<<"non c' e' nessuna lista"<<std::endl;
    }
}

int ShoppingListManager::getlistnumber() const {
    return this->listnumber;
}

void ShoppingListManager::setlistnumber(int n) {
    listnumber+=n;
}


void ShoppingListManager::showonelist(const ShoppingList* const list) {
    for(auto &itr:lists){
        if(itr->getlistname()==list->getlistname()) {
            itr->printlist();
        }
    }
}


bool ShoppingListManager::renamelist(const std::string &newname, const std::string& oldname) {
    bool oldNameFound = false;
    for (auto &itr: lists) {
        if (itr->getlistname() == oldname) {
            oldNameFound=true;
            if (itr->getlistname() == newname) {
                std::cout << "nome gia' esistente!" << std::endl;
                return false;
            }else {
                itr->renamelistname(newname);
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
        if(itr->getlistname()==name){
            itr->insertobject(obj);
        }else{
            std::cout<<"lista non riconosciuta"<<std::endl;
        }
    }
}

void ShoppingListManager::removeobject(const std::string& name, int pos) {
    for(auto &itr:lists) {
        if (itr->getlistname()== name) {
            itr->removeobject(pos);
        }
    }
}

void ShoppingListManager::modifysingleobjectquantity(const std::string& name, const float &goalq, int pos) {
    for(auto &itr:lists) {
        if (itr->getlistname()==name) {
            itr->modifysingleobjectquantity(goalq, pos);
        }
    }
}

void ShoppingListManager::calcolatetotal(const std::string &name) {
    for(auto &itr:lists){
        if(itr->getlistname()==name){
            itr->calcoltotal();
        }
    }
}

const ShoppingList *ShoppingListManager::getlist(const std::string &name){
    for(const auto &itr:lists){
        if(itr->getlistname()==name){
            return itr->getlist();
        }
    }
}

bool ShoppingListManager::findlist(const std::string &name) {
    for(const auto itr:lists){
        if(itr->getlistname()==name){
            return true;
        }
    }
    return false;
}

void ShoppingListManager::copylist(const std::string &name) {
    std::string Newname=name+"copied";
    for(auto &itr:lists){
        if(itr->getlistname()==name){
            ShoppingList copylist(*itr->getlist());
            copylist.renamelistname(Newname);
            insertShoppinglist(new ShoppingList(copylist));;
            notify();
            std::cout<<"lista copiata!"<<std::endl;
            break;
        }
    }
}
