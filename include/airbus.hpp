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
        Node * insert (int key, Node * node, Node * parent = nullptr);
        Node * remove (int key, Node * node);
        Node * search (int key, Node * node);

        int nthInorder(Node * node, int ref) {
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

        int posInorder(Node * node, int ref) {
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

        int maxDepth(Node * node) {  
            if (node == nullptr)  
                return 0;  
            else {  
                int lDepth = maxDepth(node->left);  
                int rDepth = maxDepth(node->right);  
            
                if (lDepth > rDepth) return(lDepth + 1);  
                else return(rDepth + 1);  
            }  
        }  

        Node * minValueNode (Node * node);

        public:
        BST (Node * r = nullptr) : root{r} {}

        void inserir (int key) { root = insert (key, root); }  
        void remover (int key) { root = remove (key, root); }
        Node * buscar (int key) { return search (key, root); } 

        int enesimoElemento(int index) { 
            return nthInorder(root, index);
        }

        int posicao(int key) {
            return posInorder(root, key);
        }

        bool ehCheia() {
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

        bool ehCompleta() {
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

        std::string toString ();  

    };
}

#endif