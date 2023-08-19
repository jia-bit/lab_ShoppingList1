//
// Created by jialu on 19/08/23.
//

#include "gtest/gtest.h"
#include "../Object.h"

TEST(Object, DefaultConstructor){
    Object ob;
    ASSERT_EQ(0, ob.getunitprice());
    ASSERT_EQ(0, ob.getquantity());
    ASSERT_EQ(0, ob.getprice());
}

TEST(Object, TestPrice){
    Object ob;
    ob.setunitprice(0.6);
    ob.setquantity(10);
    ob.setprice();
    ASSERT_EQ(6, ob.getprice());
}