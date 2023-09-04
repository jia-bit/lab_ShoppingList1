//
// Created by daiji on 25/07/2023.
//

#ifndef LAB_SHOPPINGLIST1_SHOPPINGLISTMANAGER_H
#define LAB_SHOPPINGLIST1_SHOPPINGLISTMANAGER_H


#include <vector>
#include "Subject.h"
#include "ShoppingList.h"

class ShoppingListManager: public Subject {
public:
    ShoppingListManager();
    void notify() override;
    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;

    void insertShoppinglist(ShoppingList* newlist);
    void deleteShoppinglist(int pos);
    void printLists();
    int getListNumber()const;
    void setListNumber(int n);

    void showOneList(const std::string &name); //riceve il nome della lista
    bool renameList(const std::string& newname, const std::string& oldname);
    void insertnewObject(const std::string& name, const Object& obj);
    void removeObject(const std::string& name, int pos);
    void modifyObjectQuantity(const std::string& name, int goalq, int pos);
    const ShoppingList* getList(const std::string& name);
    bool findList(const std::string& name);
    void copyList(const std::string& name);
    void setObjectbeBought(int pos, const std::string &name);
private:
    std::list<Observer*> observers;
    std::vector< ShoppingList*> lists;
    int listnumber;
};


#endif //LAB_SHOPPINGLIST1_SHOPPINGLISTMANAGER_H
