//
// Created by daiji on 19/08/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"

TEST(ShoppingList, DefaultConstructor){
    ShoppingList list;
    ASSERT_EQ(0, list.getTotal());
}

TEST(ShoppingList, TestQuantityTotal){
    ShoppingList list;
    Object ob1("birre", "alcool", 1.47, 10);
    Object ob2("pane", "cereali", 2.31, 1);

    list.insertObject(ob1);
    list.insertObject(ob2);
    ASSERT_NEAR(17.01, list.getTotal(), 0.01);
    ASSERT_EQ(0, list.getnumberBought());

    list.setObjectbeBought(0);
    ASSERT_EQ(1, list.getnumberBought()); //ob1 è stato comprato

    list.modifyObjectQuantity(2, 1);
    ASSERT_NEAR(4.62, list.getTotal(), 0.01);

    list.removeObject(0); //ob1 è stato cancellato
    ASSERT_NEAR(4.62, list.getTotal(), 0.01);
    ASSERT_EQ(0, list.getnumberBought());
}


