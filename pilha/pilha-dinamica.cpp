//
// Created by Robert L Resende on 06/11/25.
//
#include "cstdio"
#include "cstdlib"

//Definição da estrutura de um nó
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//Estrutura para a pilha
typedef struct Stack {
    Node *top; //ponteiro para o topo da pilha
}Stack;

//Função para incializar a pilha
void initializeStack(Stack* stack){
    stack -> top = NULL;
}

//Função para verificar se a pilha está vazia
int isEmpty(Stack* pilha){
    return (pilha -> top == NULL);
}

//Função para criar um novo nó
Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof (Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

//Função para empilhar (inserir no topo da pilha)
void push(Stack *pilha, int data){
    Node * newNode = createNode(data);
    newNode -> next = pilha -> top;
    pilha -> top = newNode;
}

//Função para desempilhar(remover do topo da pilha)
int pop(Stack* pilha){
    if (isEmpty(pilha)){
        printf("Erro: Pilha está vazia!");
        return -1;
    }

    Node* tempo = pilha -> top;
    int poppedValue = tempo -> data;
    free(tempo);
    return poppedValue;
}

//Função para retornar o valor do topo da pilha sem remover-lo
int topValue(Stack* pilha){
    if(isEmpty(pilha)){
        printf("Erro: pilha esta vazia!\n");
        return -1;
    }
    return pilha -> top -> data;
}

//Função para exibir os elementos da pilha
void displayStack(Stack *pilha){
    if(isEmpty(pilha)){
        printf("Pilha esta vazia!\n");
        return;
    }

    Node* tempo = pilha -> top;
    while(tempo != NULL){
        printf(" %d -> " , tempo -> data);
        tempo = tempo -> next;
    }
    printf("NULL\n");
}

//Função principal para testar as operações da pilha
int main(){

    Stack pilha;
    initializeStack(&pilha);

    push(&pilha, 900);
    push(&pilha, 530);
    push(&pilha, 740);

    printf("Pilha após inserções: ");
    displayStack(&pilha);

    printf("Topo da pilha: %d\n", topValue(&pilha));
    printf("pilha após remoção");
    displayStack(&pilha);

    printf("Topo da pilha após remoção: %d\n", topValue(&pilha));

    if(isEmpty(&pilha)){
        printf("Pilha está vazia\n");
    } else{
        printf("Pilha não está vazia!\n");
    }

    return 0;
}