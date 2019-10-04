#ifndef AIRBUS_H
#define AIRBUS_H

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <math.h>

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
        unsigned long size = 0;

        Node * insert (int key, Node * node, Node * parent = nullptr);
        Node * remove (int key, Node * node);
        Node * search (int key, Node * node);
        int nthInorder(Node * node, int ref);
        int posInorder(Node * node, int ref);
        int maxDepth(Node * node);
        Node * minValueNode (Node * node);

        public:
        BST (Node * r = nullptr) : root{r} {}

        void inserir (int key) { root = insert (key, root); }  
        void remover (int key) { root = remove (key, root); }
        Node * buscar (int key) { return search (key, root); } 
        int enesimoElemento(int index) { return nthInorder(root, index); }
        int posicao(int key) { return posInorder(root, key); }
        int mediana ();
        bool ehCheia();
        bool ehCompleta();
        std::string toString ();
        unsigned long getSize () { return size; }
    };
}

#endif