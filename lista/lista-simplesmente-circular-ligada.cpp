//
// Created by Robert L Resende on 15/11/25.
//
#include <cstdio>
#include <cstdlib>

//Estrutura do nó da lista circular
typedef struct Node{
    int data;
    struct Node* proximo;
}Node;

//Estrutura da lista circular
typedef struct{
    Node* head;
}CircularLinkedList;

//Função para inicializar a lista
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Erro de alocacao na memoria\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> next = newNode;//O nó aponta para si mesmo
    return newNode;
}

int main(){
    
}