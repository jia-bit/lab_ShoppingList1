#include <iostream>
#include <string>
#include "ShoppingListManager.h"
#include "UserView.h"
#include "ListNumberObserver.h"


int main() {
    ShoppingListManager manager;
    UserView user(&manager);

    int c, f, pos;
    std::string newlistName, listname, oldname, newname, NameObj, Type;
    float UnitPrice, Quantity, goalquantity;
    bool returnmenu;

    Object* obj;
    ShoppingList *newlist;
    ListNumberObserver ob1(&manager);

    while (true) {
        user.Menu();
        std::cin >> c;
        switch (c) {
            case 1: //mostra tutte le liste
                ob1.printalllists();
                break;
            case 2: //crea newlist
                std::cout << "creare una nuova lista con nome: " << std::endl;
                std::cin >> newlistName;
                newlist=new ShoppingList(newlistName);
                std::cout<<std::endl;
                user.insertnewlist(newlist);
            loop:
                returnmenu=false;
                user.Displayinlist();
                while (!returnmenu) {
                    std::cin >> f;
                    switch (f) {
                        case 1:
                            std::cout << "inserisci nome di oggetto: " << std::endl;
                            std::cin >> NameObj;
                            std::cout << "inserisci prezzo unitario di oggetto: " << std::endl;
                            std::cin >> UnitPrice;
                            std::cout << "inserisci quantita' di oggetto: " << std::endl;
                            std::cin >> Quantity;
                            std::cout << "inserisci tipo: " << std::endl;
                            std::cin >> Type;
                            obj=new Object(NameObj, Type, UnitPrice, Quantity);
                            newlist->insertobject(*obj);
                            newlist->calcoltotal();
                            newlist->printlist();
                            std::cout<<"totale di "<<newlist->getlistname()<<" : "<<newlist->gettotal()<<std::endl;
                            goto loop;
                        case 2:
                            std::cout<<"inserisci posizione di oggetto da cancellare: "<<std::endl;
                            std::cin>>pos;
                            manager.removeobject(newlistName, pos);
                            newlist->calcoltotal();
                            newlist->printlist();
                            std::cout<<"total di "<<newlist->getlistname()<<" : "<<newlist->gettotal()<<std::endl;
                            goto loop;
                        case 3:
                            std::cout<<"inserisci nuova quantita': "<<std::endl;
                            std::cin>>goalquantity;
                            std::cout<<"inserisci posizione di oggetto: "<<std::endl;
                            std::cin>>pos;
                            newlist->modifysingleobjectquantity(goalquantity, pos);
                            newlist->calcoltotal();
                            newlist->printlist();
                            std::cout<<"total: "<<newlist->gettotal()<<std::endl;
                            goto loop;
                        case 4:
                            returnmenu=true;
                            break;
                        default:
                            std::cout<<"numero non riconosciuto"<<std::endl;
                            goto loop;
                    }
                }
                break;

            case 3: //mostra lista
                std::cout << "inserisci il nome della lista da mostrare: " << std::endl;
                std::cin >> listname;
                while(!manager.findlist(listname)){
                std::cout << "riinserisci il nome della lista da mostrare: " << std::endl;
                std::cin >> listname;
                }
                user.showonelist(manager.getlist(listname));
            loop1:
                returnmenu=false;
                user.Displayinlist();
                while (!returnmenu) {
                    std::cin >> f;
                    switch (f) {
                        case 1:
                            std::cout << "inserisci nome di oggetto: " << std::endl;
                            std::cin >> NameObj;
                            std::cout << "inserisci prezzo unitario di oggetto: " << std::endl;
                            std::cin >> UnitPrice;
                            std::cout << "inserisci quantita' di oggetto: " << std::endl;
                            std::cin >> Quantity;
                            std::cout << "inserisci tipo di oggetto: " << std::endl;
                            std::cin >> Type;
                            obj=new Object(NameObj, Type, UnitPrice, Quantity);
                            manager.insertnewObject(listname, *obj);
                            manager.calcolatetotal(listname);
                            user.showonelist(manager.getlist(listname));
                            goto loop1;
                        case 2: //cancella oggetti
                            std::cout<<"inserisci posizione di oggetto da cancellare: "<<std::endl;
                            std::cin>>pos;
                            user.removeobject(listname,pos);
                            manager.calcolatetotal(listname);
                            user.showonelist(manager.getlist(listname));
                            goto loop1;
                        case 3: //modifica quantita'
                            std::cout<<"inserisci nuova quantita': "<<std::endl;
                            std::cin>>goalquantity;
                            std::cout<<"inserisci posizione di oggetto: "<<std::endl;
                            std::cin>>pos;
                            manager.modifysingleobjectquantity(listname,goalquantity, pos);
                            manager.calcolatetotal(listname);
                            user.showonelist(manager.getlist(listname));
                            goto loop;
                        case 4:
                            returnmenu=true;
                            break;
                        default:
                            std::cout<<"numero non riconosciuto"<<std::endl;
                            goto loop1;
                    }
                }
                break;
            case 4://cancella lista
                std::cout << "inserisci il nome della lista da cancellare: " << std::endl;
                std::cin >> listname;
                manager.deleteShoppinglist(pos);
                user.printallLists();
                break;
            case 5: //rinomina nome
                std::cout << "inserisci nome vecchio: " << std::endl;
                std::cin >> oldname;
                std::cout << "inserisci nome nuovo: " << std::endl;
                std::cin>>newname;
                user.renamelistname(newname, oldname);
                user.printallLists();
                break;

            default:
                std::cout<<"numero non conosciuto"<<std::endl;
                break;
        }
    }
}
