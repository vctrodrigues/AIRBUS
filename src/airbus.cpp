#include "../include/airbus.hpp"

#include <iostream>

using namespace airbus;

Node * BST::insert (int key, Node * node) {
    // If node is null, insert key as root
    if (node == nullptr) {
        node = new Node(key);
    } else if (key > node->key) {
        node->right = insert (key, node->right);
        std::cout << "Node added to right!" << std::endl;
    } else if (key < node->key) {
        node->left = insert (key, node->left);
        std::cout << "Node added to left!" << std::endl;
    } else {
        std::cout << "Element already in the tree!" << std::endl;
    }

    return node;
}

void BST::toString () {
    if (root == nullptr)
        return;

    std::queue<Node *> q;
    q.push(root);

    while (q.empty() == false) {
        Node * node = q.front();
        std::cout << node->key << " ";
        q.pop();

        if (node->left != nullptr)
            q.push(node->left);
        
        if (node->right != nullptr)
            q.push(node->right);
    }
}