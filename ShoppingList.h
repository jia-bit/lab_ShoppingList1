//
// Created by daiji on 25/07/2023.
//

#ifndef LAB_SHOPPINGLIST1_SHOPPINGLIST_H
#define LAB_SHOPPINGLIST1_SHOPPINGLIST_H


#include <list>
#include <vector>
#include "Subject.h"
#include "Object.h"
#include "Observer.h"

class ShoppingList : public Subject{
public:
    ShoppingList(const std::string& n);
    ShoppingList(){}
    ~ShoppingList();

    ShoppingList(const ShoppingList& orig);
    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;

    ShoppingList& operator=(const ShoppingList& right);
    void insertobject(const Object& value);
    void removeobject(int pos);
    void printlist();
    float gettotal()const;
    std::string getlistname() const;
    void renamelistname(const std::string& name);
    void calcoltotal();
    void modifysingleobjectquantity(const float& goalq, int pos);

private:
    std::list<Observer*> observers;
    std::vector<Object> list;
    float total;
    std::string listname;
};


#endif //LAB_SHOPPINGLIST1_SHOPPINGLIST_H
