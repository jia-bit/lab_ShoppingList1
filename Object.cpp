//
// Created by daiji on 25/07/2023.
//

#include "Object.h"
Object::Object(const std::string &n, const std::string &t, float up, float q){
    name=n;
    type=t;
    unitprice=up;
    quantity=q;
    price=up*q;
}

Object::Object():unitprice(0), quantity(0) {
    price=unitprice*quantity;
}


float Object::getprice() const {
    return this->price;
}

void Object::setquantity(const float &q) {
    quantity=q;
}

std::string Object::getname() const {
    return this->name;
}

float Object::getquantity() const {
    return this->quantity;
}

float Object::getunitprice() const {
    return this->unitprice;
}

void Object::setprice() {
    price=unitprice*quantity;
}

std::string Object::gettype() const {
    return this->type;
}

void Object::setunitprice(const float &uq) {
    this->unitprice=uq;
}

