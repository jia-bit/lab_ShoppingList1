//
// Created by daiji on 25/07/2023.
//

#ifndef LAB_SHOPPINGLIST1_OBSERVER_H
#define LAB_SHOPPINGLIST1_OBSERVER_H

class Observer {
public:
    virtual void update()=0;
    virtual ~Observer() {};
};

#endif //LAB_SHOPPINGLIST1_OBSERVER_H
