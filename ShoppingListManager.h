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
    void printlists();
    int getlistnumber()const;
    void setlistnumber(int n);

    ShoppingList* creatlist(const std::string& name);
    void showonelist(const ShoppingList * const list);
    void renamelist(const std::string& newname, const std::string& origilname);
    void insertnewObject(const std::string& name, const Object& obj);
    void removeobject(const std::string& name, int pos);
    void modifysingleobjectquantity(const std::string& name, const float& goalq, int pos);
    void calcolatetotal(const std::string& name);
    const ShoppingList* getlist(const std::string& name);
    bool findlist(const std::string& name);
private:
    std::list<Observer*> observers;
    std::vector< ShoppingList*> lists;
    int listnumber;
};


#endif //LAB_SHOPPINGLIST1_SHOPPINGLISTMANAGER_H
