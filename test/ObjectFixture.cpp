//
// Created by jialu on 19/08/23.
//

#include "gtest/gtest.h"
#include "../Object.h"

class ObjectSuite: public::testing::Test{
protected:
    virtual void SetUp(){
        ob.setunitprice(6);
        ob.setquantity(10);
    }
    Object ob;
};

TEST_F(ObjectSuite, TestPrice){
    ASSERT_EQ(6, ob.getunitprice());
    ASSERT_EQ(10, ob.getquantity());
    ob.setprice();
    ASSERT_EQ(60, ob.getprice());
}