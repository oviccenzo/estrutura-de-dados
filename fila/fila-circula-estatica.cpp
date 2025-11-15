//
// Created by Robert L Resende on 05/11/25.
//
//implementação de fila circular estatica em vetor
#include "cstdio"
#include "cstdlib"
#define Max 100 //tamanho da fila

//estrutura da fila
typedef struct {
    int data[Max];
    int front;
    int rear;
    int size;
}Queue;

//inicializa a fila
void initializeQueue(Queue *q){
    q -> front = 0;
    q -> rear = 0;
    q -> size = 0;
}

//verifica se a fila esta cheia
int isFull(Queue *q){
    return (q -> size == Max);
}

//Verifica se a fila esta vazia
int isEmpty(Queue *q){
    return (q -> size == 0);
}

//Verifica se a fila está vazia
int enqueue(Queue *q, int valor){
    if(isFull(q)){
        printf("Fila esta cheia. Nao e possivel inseirir na fila: %d\n", valor);
        return 0;
    }

    q -> data[q -> rear] = valor;
    q -> rear = (q -> rear + 1) % Max;
    q -> size++;
    return 1;
}

//Remove um valor na fila
int dequeue(Queue *q, int *valor){
    if(isEmpty(q)){
        printf("Fila esta cheia. Nao e possivel remover da fila!\n");
        return 0;
    }

    *valor = q -> data[q -> front];
    q -> front = (q -> front + 1) % Max ;
    q -> size--;
    return 1;
}

//Retorna o valor da cabeça da fila sem remover
int front(Queue *q, int *valor){
    if(isEmpty(q)){
        printf("Fila esta vazia. Sem elemento na cabeca da fila!.\n");
        return 0;
    }
    *valor = q -> data[q -> front];
    return 1;
}

//Exibe todos os elementos da fila
void displayQueue(Queue *q){
    int index;

    if(isEmpty(q)){
        printf("Fila esta vazia\n");
        return;
    }
    printf("Elementos na fila: ");
    for (int i = 0; i < q -> size; ++i) {
        index = (q -> front + 1) % Max;
        printf("%d ", q -> data[index]);
    }
    printf("\n");
}

int main(){

    //Criando e inicializando a fila
    Queue myQueue;
    initializeQueue(&myQueue, 10);
    initializeQueue(&myQueue, 10);
    initializeQueue(&myQueue, 10);

    //Inserindo elementos na fila
    enqueue(&myQueue);

    //Exibindo a fila
    displayQueue(&myQueue);

    //Removendo um elemento na fila
    int valor;
    if(dequeue(&myQueue, &valor)){
        printf("Elementos removido da fila: %d\n", valor);
    }

    //Exibindo a fila novamente
    displayQueue(&myQueue);

    //Inserindo mais elementos
    enqueue(&myQueue, 70);
    enqueue(&myQueue, 90);
    enqueue(&myQueue, 120);

    displayQueue(&myQueue);

    return 0;
}
