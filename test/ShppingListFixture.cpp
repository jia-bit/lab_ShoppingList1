//
// Created by daiji on 19/08/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"

class ShoppingListSuite : public ::testing::Test {
protected:
    ShoppingList list;
    virtual void SetUp(){
        Object ob1("birre", "alcool", 1.47, 10);
        Object ob2("pane", "cereali", 2.31, 1);

        list.insertObject(ob1);
        list.insertObject(ob2);
    }


};

TEST_F(ShoppingListSuite, TestTotal){
    ASSERT_NEAR(17.01, list.getTotal(), 0.01);
}