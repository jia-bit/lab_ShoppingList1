cmake_minimum_required(VERSION 3.25)
project(lab_ShoppingList1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_ShoppingList1 main.cpp Subject.h Observer.h Object.cpp Object.h ShoppingList.cpp ShoppingList.h ShoppingListManager.cpp ShoppingListManager.h ShoppingListObserver.cpp ShoppingListObserver.h ListNumberObserver.cpp ListNumberObserver.h UserView.cpp UserView.h)
