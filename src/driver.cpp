#include "../include/airbus.hpp"

#include <iostream>

using namespace airbus;

int main () {
    BST tree;

    tree.inserir(10);
    tree.inserir(20);
    tree.inserir(5);
    tree.inserir(15);
    tree.inserir(3);
    tree.inserir(21);

    std::cout << " >>> Testando toString()" << std::endl;    
    std::cout << tree.toString() << std::endl;

    std::cout << " >>> Buscando key {10}" << std::endl;    
    std::cout << tree.buscar(10)->key << std::endl;

    std::cout << " >>> enesimoElemento {3}" << std::endl;   
    std::cout << tree.enesimoElemento(5) << std::endl;

    std::cout << " >>> posicao {15}" << std::endl;    
    std::cout << tree.posicao(10) << std::endl;

    std::cout << " >>> mediana" << std::endl; 
    std::cout << tree.mediana() << std::endl;

    std::cout << " >>> ehCheia" << std::endl;    
    std::cout << tree.ehCheia() << std::endl;

    std::cout << " >>> ehCompleta" << std::endl;    
    std::cout << tree.ehCompleta() << std::endl;

    std::cout << " >>> Removendo 20" << std::endl;   
    tree.remover(10);    
    std::cout << tree.toString() << std::endl;

    return 0;
}