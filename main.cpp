#include <iostream>
#include <string>
#include "ShoppingListManager.h"
#include "UserView.h"
#include "ListNumberObserver.h"


int main() {
    ShoppingListManager manager;
    UserView user(&manager);

    int c, f, pos, Quantity, goalquantity;
    std::string newlistName, listname, oldname, newname, NameObj, Type;
    float UnitPrice;
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
                manager.insertShoppinglist(newlist);
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
                            newlist->insertObject(*obj);
                            newlist->calculateTotal();
                            newlist->printList();
                            std::cout << "totale di " << newlist->getListName() << " : " << newlist->getTotal() << std::endl;
                            goto loop;
                        case 2:
                            std::cout<<"inserisci posizione di oggetto da cancellare: "<<std::endl;
                            std::cin>>pos;
                            manager.removeObject(newlistName, pos);
                            newlist->calculateTotal();
                            newlist->printList();
                            std::cout << "total di " << newlist->getListName() << " : " << newlist->getTotal() << std::endl;
                            goto loop;
                        case 3:
                            std::cout<<"inserisci nuova quantita': "<<std::endl;
                            std::cin>>goalquantity;
                            std::cout<<"inserisci posizione di oggetto: "<<std::endl;
                            std::cin>>pos;
                            newlist->modifyObjectQuantity(goalquantity, pos);
                            newlist->calculateTotal();
                            newlist->printList();
                            std::cout << "total: " << newlist->getTotal() << std::endl;
                            goto loop;
                        case 4:
                            newlist->printList();
                            std::cout<<"inserisci posizione di oggetto: "<<std::endl;
                            std::cin>>pos;
                            newlist->setObjectbeBought(pos);
                            break;
                        case 5:
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
                while(!manager.findList(listname)){
                std::cout << "riinserisci il nome della lista da mostrare: " << std::endl;
                std::cin >> listname;
                }
                manager.showOneList(listname);
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
                            manager.showOneList(listname);
                            goto loop1;
                        case 2: //cancella oggetti
                            std::cout<<"inserisci la posizione di oggetto da cancellare: "<<std::endl;
                            std::cin>>pos;
                            manager.removeObject(listname,pos);
                            manager.showOneList(listname);
                            //manager.calculateTotal(listname);
                            goto loop1;
                        case 3: //modifica quantita'
                            std::cout<<"inserisci nuova quantita': "<<std::endl;
                            std::cin>>goalquantity;
                            std::cout<<"inserisci posizione di oggetto: "<<std::endl;
                            std::cin>>pos;
                            manager.modifyObjectQuantity(listname, goalquantity, pos);
                            manager.showOneList(listname);
                            goto loop;
                        case 4:
                            std::cout<<"inserisci posizione di oggetto: "<<std::endl;
                            std::cin>>pos;
                            manager.setObjectbeBought(pos, listname);
                            manager.showOneList(listname);
                            break;
                        case 5:
                            returnmenu=true;
                            break;
                        default:
                            std::cout<<"numero non riconosciuto"<<std::endl;
                            goto loop1;
                    }
                }
                break;
            case 4://cancella lista
                manager.printLists();
                std::cout << "inserisci la posizione della lista da cancellare: " << std::endl;
                std::cin >> pos;
                manager.deleteShoppinglist(pos);
                manager.printLists();
                break;
            case 5: //rinomina nome
                manager.printLists();
            loop2:
                std::cout << "inserisci nome vecchio: " << std::endl;
                std::cin >> oldname;
                std::cout << "inserisci nome nuovo: " << std::endl;
                std::cin>>newname;
                if(!manager.renameList(newname, oldname)){
                    goto loop2;
                }
                ob1.printalllists();
                break;
            case 6: //copia la lista
                manager.printLists();
                std::cout<<"inserisci il nome della lista da copiare: "<<std::endl;
                std::cin>>listname;
                while(!manager.findList(listname)){
                    std::cout<<"riinserisci il nome della lista da copiare: "<<std::endl;
                    std::cin>>listname;
                }
                manager.copyList(listname);
                ob1.printalllists();
                break;

            default:
                std::cout<<"numero non conosciuto"<<std::endl;
                break;
        }
    }
}
