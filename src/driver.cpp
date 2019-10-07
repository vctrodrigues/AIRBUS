#include "../include/airbus.hpp"

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace airbus;

/**
int main()
{
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
  std::cout << tree.enesimoElemento(3) << std::endl;

  std::cout << " >>> enesimoElemento {5}" << std::endl;
  std::cout << tree.enesimoElemento(5) << std::endl;

  std::cout << " >>> posicao {15}" << std::endl;
  std::cout << tree.posicao(15) << std::endl;

  std::cout << " >>> posicao {10}" << std::endl;
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
*/

int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    //Creating tree
    BST tree;

    //Reading input file
    FILE *inputFile;
    inputFile = fopen(argv[1], "r");
    if (inputFile != NULL)
    {
      while (!feof(inputFile))
      {
        int key;
        fscanf(inputFile, "%d", &key);
        std::cout << ">>> Inserindo { " << key << " } na árvore." << std::endl;
        tree.inserir(key);
      }
    }
    else
    {
      std::cout << ">>> ERRO: Arquivo inexistente." << std::endl;
    }

    //Reading commands file
    FILE *commandsFile;
    commandsFile = fopen(argv[2], "r");
    if (commandsFile != NULL)
    {
      while (!feof(commandsFile))
      {
        std::string command;
        int arg;

        std::stringstream stream;
        char c = fgetc(commandsFile);
        do
        {
          stream << c;
          c = fgetc(commandsFile);
        } while (strcmp(" ", &c) != 0 && strcmp("\n", &c) != 0);
        command = stream.str();

        stream.str("");
        stream.clear();

        bool hasNumber = fscanf(commandsFile, "%d\n", &arg);

        if (strcmp("ENESIMO", command.c_str()) == 0 && hasNumber)
        {
          std::cout << ">>> Enésimo Elemento { " << arg << " }:" << std::endl;
          std::cout << "\t" << tree.enesimoElemento(arg) << std::endl;
        }
        else if (strcmp("POSICAO", command.c_str()) == 0 && hasNumber)
        {
          std::cout << ">>> Posição { " << arg << " }:" << std::endl;
          std::cout << "\t" << tree.posicao(arg) << std::endl;
        }
        else if (strcmp("INSIRA", command.c_str()) == 0 && hasNumber)
        {
          std::cout << ">>> Inserir { " << arg << " }:" << std::endl;
          std::cout << "\tInserindo { " << arg << " } na árvore." << std::endl;
          tree.inserir(arg);
        }
        else if (strcmp("REMOVA", command.c_str()) == 0 && hasNumber)
        {
          std::cout << ">>> Remover { " << arg << " }:" << std::endl;
          std::cout << "\tRemovendo { " << arg << " } da árvore." << std::endl;
          tree.remover(arg);
        }
        else if (strcmp("IMPRIMA", command.c_str()) == 0)
        {
          std::cout << ">>> Imprimindo árvore..." << std::endl;
          std::cout << "\t" << tree.toString() << std::endl;
        }
        else if (strcmp("MEDIANA", command.c_str()) == 0)
        {
          std::cout << ">>> Mediana" << std::endl;
          std::cout << "\t" << tree.mediana() << std::endl;
        }
        else if (strcmp("CHEIA", command.c_str()) == 0)
        {
          std::cout << ">>> Árvore Cheia" << std::endl;
          if (tree.ehCheia())
            std::cout << "\tSim" << std::endl;
          else
            std::cout << "\tNão" << std::endl;
        }
        else if (strcmp("COMPLETA", command.c_str()) == 0)
        {
          std::cout << ">>> Árvore Completa" << std::endl;
          if (tree.ehCompleta())
            std::cout << "\tSim" << std::endl;
          else
            std::cout << "\tNão" << std::endl;
        }
        else
        {
          std::cout << ">>> ERRO: Comando inválido..." << std::endl;
          std::cout << "\tComando: " << command << std::endl;
        }
      }
    }
    else
    {
      std::cout << ">>> ERRO: Arquivo inexistente." << std::endl;
    }
  }
  else
  {
    std::cout << ">>> ERRO: Comandos insuficientes. Use ./bin/airbus <arquivo_entrada> <arquivo_comandos>." << std::endl;
  }

  std::cout << ">>> Finalizando programa..." << std::endl;
}