#include "../include/airbus.hpp"

#include <iostream>
#include <sstream>

using namespace airbus;

Node * BST::insert (int key, Node * node, Node * parent) {
    if (node == nullptr) {
        node = new Node(key, nullptr, nullptr, parent);
    } else if (key > node->key) {
        node->right = insert (key, node->right, node);
    } else if (key < node->key) {
        node->left = insert (key, node->left, node);
    }

    return node;
}

Node * BST::search (int key, Node * node) {
    if (node == nullptr || node->key == key)
        return node;

    if (node->key < key)
        return search(key, node->right);

    return search(key, node->left);
}

Node * BST::minValueNode (Node * node) { 
    Node * current = node; 
  
    while (current && current->left != nullptr) 
        current = current->left; 
  
    return current; 
} 

Node * BST::remove (int key, Node * node) {
    if (node == nullptr)
        return node;
    
    if (key < node->key) {
        node->left = remove(key, node->left);
    } else if (key > node->key) {
        node->right = remove(key, node->right);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            Node * temp = node->right;
            temp->parent = node->parent;
            delete node;            
            return temp;
        } else if (node->right == nullptr) {
            Node * temp = node->left;
            temp->parent = node->parent;
            delete node;
            return temp;
        }

        Node * sucessor = minValueNode (node->right);
        node->key = sucessor->key;
        node->right = remove(sucessor->key, node->right);
    }

    return node;
}

std::string BST::toString () {
    if (root == nullptr)
        return "";

    std::queue<Node *> q;
    q.push(root);

    std::stringstream stream;
    while (q.empty() == false) {        
        Node * node = q.front();
        stream << node->key << " ";
        q.pop();

        if (node->left != nullptr)
            q.push(node->left);
        
        if (node->right != nullptr)
            q.push(node->right);
    }

    return stream.str();
}