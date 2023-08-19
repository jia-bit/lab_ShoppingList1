//
// Created by daiji on 19/08/2023.
//

#include "gtest/gtest.h"

#include "../ShoppingListManager.h"

class ShoppingListManagerSuite: public ::testing::Test {
protected:
    ShoppingListManager s;
    virtual void SetUp(){
        ShoppingList list1("first");
        ShoppingList list2("second");

        s.insertShoppinglist(&list1);
        s.insertShoppinglist(&list2);
        s.copylist("first");
    }

};

TEST_F(ShoppingListManagerSuite, TestManager){
    ASSERT_EQ(3, s.getlistnumber());
}