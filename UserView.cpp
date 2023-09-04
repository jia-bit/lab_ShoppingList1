//
// Created by daiji on 25/07/2023.
//

#include <iostream>
#include "UserView.h"

UserView::UserView(ShoppingListManager *ls): lists(ls) {}


void UserView::Menu() {
    std::cout<<"*****************************"<<std::endl;
    std::cout<<"*********************  Menu  ********************"<<std::endl;
    std::cout<<"1. mostra tutte le liste"<<std::endl;
    std::cout<<"2. crea una nuova lista"<<std::endl;
    std::cout<<"3. mostra una lista"<<std::endl;
    std::cout<<"4. cancella la lista"<<std::endl;
    std::cout<<"5. rinomina la lista"<<std::endl;
    std::cout<<"6. copia la lista"<<std::endl;
    std::cout<<"insesci il numero............."<<std::endl;
}


void UserView::Displayinlist() {
    std::cout<<"**********************************************"<<std::endl;
    std::cout<<"1. inserisce un nuovo oggetto"<<std::endl;
    std::cout<<"2. cancella un oggetto"<<std::endl;
    std::cout<<"3. modifica quantita' di oggetto"<<std::endl;
    std::cout<<"4. segna oggetto comprato"<<std::endl;
    std::cout<<"5. torna alla menu: "<<std::endl;
    std::cout<<"insesci il numero............."<<std::endl;
}


void UserView::insertnewlist(ShoppingList* newlist) {
    lists->insertShoppinglist(newlist);
}


