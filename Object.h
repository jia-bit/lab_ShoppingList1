//
// Created by daiji on 25/07/2023.
//

#ifndef LAB_SHOPPINGLIST1_OBJECT_H
#define LAB_SHOPPINGLIST1_OBJECT_H


#include <string>

class Object {
public:
    Object(const std::string& n, const std::string& t, float up, float q);
    Object();

    float getPrice()const;
    void setPrice();
    float getUnitPrice() const;
    int getQuantity()const;
    std::string getName()const;
    std::string getType()const;
    void setQuantity(const int& q);
    void setUnitPrice(const float& uq);
    void setbeBought(bool bebought);
    bool getbeBought();
private:
    std::string Name;
    std::string Type;
    float UnitPrice;
    int Quantity;
    float Price;
    bool beBought;
};


#endif //LAB_SHOPPINGLIST1_OBJECT_H
