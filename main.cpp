#include <iostream>
#include "ShoppingListManager.h"
#include "UserView.h"

int main() {
    ShoppingListManager manager;
    UserView user(&manager);

    int c, f, pos;
    std::string newlistName, listname, oldname, newname, NameObj, Type;
    float UnitPrice, Quantity;
    bool returnmenu;

    Object* obj;
    ShoppingList *newlist;

    while (true) {
        user.Menu();
        std::cin >> c;
        switch (c) {
            case 1: //mostra tutte le liste
                user.printallLists();
                break;
            case 2: //crea newlist
                std::cout << "creare una nuova lista con nome: " << std::endl;
                std::cin >> newlistName;
                newlist = new ShoppingList(newlistName);
                user.insertnewlist(*newlist);
                returnmenu=false;
                user.Displayinlist();
                while (!returnmenu) {
                    std::cin >> f;
                    switch (f) {
                        case 1:
                            std::cout << "inserisci nome di oggetto: " << std::endl;
                            std::cin >> NameObj;
                            std::cout << "inserisci tipo di oggetto: " << std::endl;
                            std::cin >> Type;
                            std::cout << "inserisci prezzo unitario di oggetto: " << std::endl;
                            std::cin >> UnitPrice;
                            std::cout << "inserisci quantita' di oggetto: " << std::endl;
                            std::cin >> Quantity;
                            obj=new Object(NameObj, Type, UnitPrice, Quantity);
                            newlist->insertobject(*obj);
                            user.Displayinlist();
                            break;
                        case 2:
                            std::cout<<"inserisci posizione di oggetto da cancellare: "<<std::endl;
                            std::cin>>pos;
                            user.removeobject(newlistName, pos);
                            user.Displayinlist();
                            break;
                        case 3:
                            returnmenu=true;
                            break;
                        default:
                            std::cout<<"numero non riconosciuto"<<std::endl;
                            user.Displayinlist();
                            break;
                    }
                }
                break;
            case 3: //mostra lista
                std::cout << "inserisci il nome della lista da mostrare: " << std::endl;
                std::cin >> listname;
                user.showonelist(listname);
                break;
            case 4://cancella lista
                std::cout << "inserisci il nome della lista da cancellare: " << std::endl;
                std::cin >> listname;
                manager.deleteShoppinglist(listname);
                break;
            case 5: //rinomina nome
                std::cout << "inserisci nome vecchio: " << std::endl;
                std::cin >> oldname;
                std::cout << "inserisci nome nuovo: " << std::endl;
                std::cin>>newname;
                user.renamelistname(newname, oldname);
                break;

            default:
                std::cout<<"numero non conosciuto"<<std::endl;
                break;
        }
    }
}
