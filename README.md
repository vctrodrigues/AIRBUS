# AIRBUS

## Sumário

[1. Introdução](#1-introdução)

[2. Compilação](#2-compilação)

[3. Uso](#3-uso)

[4. Autoria](#4-autoria)

## 1. Introdução

O AIRBUS (**Á**rvore B**i**ná**r**ia de **Bus**ca) é uma implementação em C++ da estrutura de dados conhecida como _Binary Search Tree_. Nela, foram implementadas as operações básicas de inserção, busca e remoção assim como métodos para encontrar o enésimo elemento em ordem simétrica, descobrir a posição em ordem simétrica de um elemento, a mediana da árvore, descobrir se ela é cheia ou completa e gerar uma string com os elementos na ordem dos níveis. Nessa implementação, só é possível guardar valores inteiros.

## 2. Compilação

Esse projeto pode ser compilado usando o [CMake](https://cmake.org). CMake é uma família de ferramentas de código aberto e multiplataforma criada para gerar, testar e empacotar programas. Basicamente, o CMake lê um script (`CMakeLists.txt`) com informações sobre o projeto e **cria um Makefile automaticamente**, tudo sob medida para as configurações do seu sistema. Depois disso, é só rodar o comando `make`, como de costume.

Para instalar o CMake em seu computador, você pode baixar o arquivo correto na página oficial e instalar ou, caso esteja utilizando o Ubuntu, pode recorrer ao instalador de pacotes padrão (`apt-get install cmake`).

Para compilar o projeto, você deve seguir os seguintes passos na página raiz:

1. `cmake -G "Unix Makefiles" ..`: pede ao cmake para criar o Makefile baseado no script encontrado em `CMakeLists.txt`.
2. `make`: compila o código do projeto e gera um executável dentro da pasta `./bin`.

## 3. Uso

Para utilizar o programa, basta executar o seguinte comando na raiz do projeto:

`./bin/airbus <caminho_para_dados> <caminho_para_comandos>`

Sendo `<caminho_para_dados>` o caminho relativo para o arquivo que contém os valores iniciais da árvore e `<caminho_para_comandos>` o caminho relativo para o arquivo que contém os comandos a serem executados em cima da árvore inicial.

> **Atenção:** para que o arquivo de comandos funcione corretamente, é necessário que ele termine com um espaço ou uma quebra de linha.

## 4. Autoria

Os autores desse projeto são **Carlos Eduardo Alves Sarmento** _< cealvesarmento@gmail.com >_ e **Victor Raphaell Vieira Rodrigues** _< victorvieira89@gmail.com >_.
