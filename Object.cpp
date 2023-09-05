//
// Created by daiji on 25/07/2023.
//

#include "Object.h"
Object::Object(const std::string &n, const std::string &t, float up, int q){
    Name=n;
    Type=t;
    UnitPrice=up;
    Quantity=q;
    Price=up*q;
    beBought=false;
}

Object::Object():UnitPrice(0), Quantity(0), beBought(false) {
    Price=UnitPrice*Quantity;
}

float Object::getPrice() const {
    return this->Price;
}

void Object::setQuantity(const int &q) {
    Quantity=q;
}

std::string Object::getName() const {
    return this->Name;
}

int Object::getQuantity() const {
    return this->Quantity;
}

float Object::getUnitPrice() const {
    return this->UnitPrice;
}

void Object::setPrice() {
    Price=UnitPrice*Quantity;
}

std::string Object::getType() const {
    return this->Type;
}

void Object::setUnitPrice(const float &uq) {
    this->UnitPrice=uq;
}

void Object::setbeBought(bool bebought) {
    this->beBought=bebought;
}

bool Object::getbeBought() const {
    return beBought;
}

