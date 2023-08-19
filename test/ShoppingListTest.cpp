//
// Created by daiji on 19/08/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"

TEST(ShoppingList, DefaultConstructor){
    ShoppingList list;
    ASSERT_EQ(0, list.gettotal());
}

TEST(ShoppingList, TestQuantityTotal){
    ShoppingList list;
    Object ob1("birre", "alcool", 1.47, 10);
    Object ob2("pane", "cereali", 5.31, 0.5);

    list.insertobject(ob1);
    list.insertobject(ob2);
    ASSERT_NEAR(17.36, list.gettotal(), 0.01);

    list.modifysingleobjectquantity(5, 0);
    ASSERT_NEAR(10.01, list.gettotal(), 0.01);

    list.removeobject(0);
    ASSERT_NEAR(2.66, list.gettotal(), 0.01);
}


