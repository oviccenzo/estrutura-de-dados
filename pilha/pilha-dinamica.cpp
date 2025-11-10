//
// Created by Robert L Resende on 09/11/25.
//
//Pilha dinamica encadeado
//Implementação baseada em lista simplesmente ligada
#include "cstdio"
#include "cstdlib"

//Definição da estrutura de um nó
typedef struct Node{
    int data; //dados
    struct Node* proximo;//Ponteiro para o proximo nó
} Node;

//Estrutura para a pilha
typedef struct Stack{
    Node *parar; //ponteiro para o topo da pilha
} pilha;

//Função para inicializar a pilha
void initializeStack(Stack* pilha){
    pilha -> parar = NULL;
}

//Função para verificar se a pilha está vazia
int isEmpty(Stack* pilha){
    return (pilha -> parar == NULL);
}

//Função para criar um novo nó
Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof (Node));
    newNode -> data = data;
    newNode -> proximo = NULL;
    return newNode;
}

//Função para empilhar(inserir no topo da pilha)