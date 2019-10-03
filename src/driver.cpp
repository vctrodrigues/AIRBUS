#include "../include/airbus.hpp"

#include <iostream>

using namespace airbus;

int main () {
    BST tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.toString();

    return 0;
}