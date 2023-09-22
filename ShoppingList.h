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
    explicit ShoppingList(const std::string& n);
    ShoppingList();
    ~ShoppingList() override;

    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;

    void insertObject(const Object& value);
    void removeObject(int pos);
    void printList() const;
    float getTotal()const;
    std::string getName() const;
    void renameList(const std::string& name);
    void calculateTotal();
    void modifyObjectQuantity(int goalq, int pos);
    const ShoppingList* getList()const;
    int getnumberBought() const;
    void setObjectbeBought(int pos);
private:
    std::list<Observer*> observers;
    std::vector<Object> list;
    float total;
    std::string listname;
};


#endif //LAB_SHOPPINGLIST1_SHOPPINGLIST_H
