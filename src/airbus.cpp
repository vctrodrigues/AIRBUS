#include "../include/airbus.hpp"

#include <iostream>
#include <sstream>

using namespace airbus;

Node * BST::insert (int key, Node * node, Node * parent) {
    if (node == nullptr) {
        node = new Node(key, nullptr, nullptr, parent);
        size++;
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

int BST::nthInorder(Node * node, int ref) {
    static int count = 0;  
    static int key = -1;  
         
    if (node == nullptr) 
        return key; 

    if (count <= ref) { 
        nthInorder(node->left, ref); 
        count++; 

        if (count == ref) 
            key = node->key;

        nthInorder(node->right, ref); 
    } 

    return key;
}

int BST::posInorder(Node * node, int ref) {
    static int count = 0;      
    static int pos = -1;   
    if (node == nullptr) 
        return pos; 


    posInorder(node->left, ref); 
    count++; 

    if (node->key == ref) 
        pos = count;

    posInorder(node->right, ref); 
    
    return pos;
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
        size--;
        
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
        size++;
    }

    return node;
}

int BST::maxDepth(Node * node) {  
    if (node == nullptr)  
        return 0;  
    else {  
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
    
        if (lDepth > rDepth) return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  

int BST::mediana () {
    int pos = size % 2 == 0 ? size / 2 : ceil(size / 2.0);
    return enesimoElemento(pos);
}

bool BST::ehCheia() {
    int n = pow(2, maxDepth(root))-1;
    int count = 0;

    if (root != nullptr) {
        std::queue<Node *> q;
        q.push(root);

        while (q.empty() == false) {        
            Node * node = q.front();
            count++;
            q.pop();

            if (node->left != nullptr)
                q.push(node->left);
            
            if (node->right != nullptr)
                q.push(node->right);
        }
    }

    return count == n;
}

bool BST::ehCompleta() {
    int count = 0;

    if (root != nullptr) {
        std::queue<Node *> q;
        q.push(root);

        while (q.empty() == false) {        
            Node * node = q.front();
            count++;
            q.pop();

            if (node->left != nullptr)
                q.push(node->left);
            
            if (node->right != nullptr)
                q.push(node->right);
        }
    }

    return maxDepth(root) == 1 + floor(log(count));
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