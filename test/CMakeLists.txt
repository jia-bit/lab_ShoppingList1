cmake_minimum_required(VERSION 3.25)
add_subdirectory(C:/Users/daiji/ClionProjects/lab_ShoppingList1/test/lib/googletest)
set(gtest_SOURCE_DIR C:/Users/daiji/ClionProjects/lab_ShoppingList1/test/lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp ObjectFixture.cpp ObjectTest.cpp ShoppingListTest.cpp ShppingListFixture.cpp ShoppingListManagerTest.cpp ShoppingListmanagerFixture.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)


