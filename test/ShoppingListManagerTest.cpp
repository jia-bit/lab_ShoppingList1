//
// Created by daiji on 19/08/2023.
//

#include "gtest/gtest.h"

#include "../ShoppingListManager.h"

TEST(ShoppingListManager, DefaultConstructor){
    ShoppingListManager s;
    ASSERT_EQ(0, s.getlistnumber());
}

TEST(ShoppingListManager, Test){
    ShoppingListManager s;
    ShoppingList list1("first");
    ShoppingList list2("second");

    s.insertShoppinglist(&list1);
    s.insertShoppinglist(&list2);
    ASSERT_EQ(2, s.getlistnumber());

    s.copylist("first");
    ASSERT_EQ(3, s.getlistnumber());

    s.deleteShoppinglist(2);
    ASSERT_EQ(2, s.getlistnumber());
    ASSERT_TRUE(true==s.findlist("second"));
}