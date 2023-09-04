//
// Created by jialu on 19/08/23.
//

#include "gtest/gtest.h"
#include "../Object.h"

class ObjectSuite: public::testing::Test{
protected:
    virtual void SetUp(){
        ob.setUnitPrice(6);
        ob.setQuantity(10);
        ob.setbeBought(true);
    }
    Object ob;
};

TEST_F(ObjectSuite, TestPrice){
    ASSERT_EQ(6, ob.getUnitPrice());
    ASSERT_EQ(10, ob.getQuantity());
    ob.setPrice();
    ASSERT_EQ(60, ob.getPrice());
    ASSERT_TRUE(ob.getbeBought());
}