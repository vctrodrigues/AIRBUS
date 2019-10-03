#ifndef AIRBUS_H
#define AIRBUS_H

#include <string>
#include <queue>

namespace airbus {
    struct Node {
        public:
        int key;
        Node * left;
        Node * right;
        Node * parent;

        Node (int k, Node * l = nullptr, Node * r = nullptr, Node * p = nullptr) : key{k}, left{l}, right{r}, parent{p} {}  
    };

    class BST {
        private:
        Node * root;
        Node * insert (int key, Node * node);

        public:
        BST (Node * r = nullptr) : root{r} {}

        void insert (int key) { root = insert (key, root); }   
        void toString ();  
    };
}

#endif