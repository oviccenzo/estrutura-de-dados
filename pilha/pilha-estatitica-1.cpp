//
// Created by Robert L Resende on 07/11/25.
//
#include "cstdio"
#define MAX 50

int topo = -1;
int pilha[MAX];

void push(int x) {
    if(topo == MAX - 2){
        printf("Pilha cheia\n!");
    } else{
        topo++;
        pilha[topo] = x;
    }
}

int pop(){
    if(topo == -1){
        printf("Pilha vazia\n");
        return -1;
    } else{
        return pilha[topo--];
    }
}

int top() {
    return pilha[topo];
}

int isEmpty(){
    return  topo == -1;
}

int main(){

    printf("verifica se a fila 0 = não ou 1 = sim: %d\n",isEmpty());
    printf("O pop gerar o numero eleatorio: %d\n",pop);
    push(12);
    push(14);
    push(16);
    printf("verifica se a fila 0 = não ou 1 = sim: %d\n",isEmpty());

    return 0;
}

