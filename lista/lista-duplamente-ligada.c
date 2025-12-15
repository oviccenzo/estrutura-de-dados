/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Implementação de lista duplamente liagda Dinamica
#include <stdio.h>
#include <stdlib.h>

//estrutura do nó da lista duplamente ligada
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

//Estrutura da lista duplamente ligada
typedef struct{
    Node* head;
    Node* tail;
}DoublyLinkedList;

//Função para inicializar a lista
void initializeList(DoublyLinkedList* list){
    list -> head = NULL;
    list -> tail = NULL;
}

//Função para criar um novo nó
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Erro de aloção de memória!\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

//Função para inserir um nó no iniício da lista
void insertAtBeginning(DoublyLinkedList* list, int data){
    Node* newNode = createNode(data);
    if(list -> head == NULL){ //Se a lista estiver vazia
        list -> head = list -> tail = newNode;
    } else{
        newNode -> next = list -> head;
        list -> head -> prev = newNode;
        list -> head = newNode;
    }
}

//Função para inserir um nó no final da lista
void insertAtEnd(DoublyLinkedList* list, int data){
    Node* newNode = createNode(data);
    if(list -> tail == NULL){ //Se a lista estiver vazia
        list -> head = list -> tail = newNode;
    } else{
        newNode -> prev = list -> tail;
        list -> tail -> next = newNode;
        list -> tail = newNode;
    }
}

//Função para remover o primeiro nó da lista
void removeFromBeginning(DoublyLinkedList* list){
    if(list -> head == NULL){
        printf("Erro: Lista esta vazia\n");
        return;
    }
    Node* tempo = list -> head;
    if(list -> head == list -> tail){ //Se houver apenas um elemento
        list -> head = list -> tail = NULL;
    } else{
        list -> head = list -> head -> next;
        list -> head -> prev = NULL;
    }
    free(tempo);
}

//Função para remover o último nó da lista
void removeFromEnd(DoublyLinkedList* list){
    if(list -> tail == NULL){
        printf("Erro: Lista esta vazia");
        return;
    }
    Node* tempo = list -> tail;
    if(list -> head = list -> tail){ //se houver apenas um elemento
        list -> head = list -> tail = NULL;
    } else{
        list -> tail = list -> tail -> prev;
        list -> tail -> next = NULL;
    }
    free(tempo);
}

//Função para buscar um valor na lista
Node* search(DoublyLinkedList* list, int value){
    Node* tempo = list -> head;
    while(tempo != NULL){
        if(tempo -> data == value){
            return tempo; //Valor encontrado
        }
        tempo = tempo -> next;
    }
    return NULL; //Vlor não encontrado
}

//Função para exibir a lista do iniício ao fim
void displayForward(DoublyLinkedList* list){
    Node* tempo = list -> head;
    printf("Lista (cabeca para cauda): ");
    while(tempo != NULL){
        printf("%d", tempo -> data);
        tempo = tempo -> next;
    }
    printf("\n");
}

//Função para exibir a lista do fim ao iniício
void displayBackward(DoublyLinkedList* list){
    Node* tempo = list -> tail;
    printf("Lista (cabeca para cauda): ");
    while(tempo != NULL){
        printf("%d", tempo -> data);
        tempo = tempo -> next;
    }
    printf("\n");
}

//Programa principal
int main(){

    DoublyLinkedList list;
    initializeList(&list);

    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);
    displayForward(&list);
    displayBackward(&list);

    insertAtBeginning(&list, 5);
    displayForward(&list);

    removeFromBeginning(&list);
    displayForward(&list);

    //Busca de um valor na lista
    int valueToSearch = 20;
    Node* searchResult = search(&list, valueToSearch);
    if(searchResult != NULL){
        printf("Valor %d encontrado na lista\n.",valueToSearch);
    } else{
        printf("Valor %d nao encontrado na lista.\n",valueToSearch);
    }

    return 0;
}