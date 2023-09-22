//
// Created by jialu on 19/08/23.
//

#include "gtest/gtest.h"
#include "../Object.h"

TEST(Object, DefaultConstructor){
    Object ob;
    ASSERT_EQ(0, ob.getUnitPrice());
    ASSERT_EQ(0, ob.getQuantity());
    ASSERT_EQ(0, ob.getPrice());
    ASSERT_FALSE(ob.isBought());
}

TEST(Object, TestPrice){
    Object ob;
    ob.setUnitPrice(0.6);
    ob.setQuantity(10);
    ob.setPrice();
    ASSERT_EQ(6, ob.getPrice());
    ASSERT_FALSE(ob.isBought());

    ob.setbeBought(true);
    ASSERT_TRUE(ob.isBought());
}