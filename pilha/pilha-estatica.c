// Programa principal usando a pilha
#include <cstdio>
#define max 100

//estrutura da pilha
typedef struct {
    int itens[max];
    int topo;
} Pilha;

//inicializa a Pilha
void initializaStack(Pilha* p) {
    p -> topo = -1;
}

//verifica se a pilha estC! vazia
int isEmpty(Pilha *p) {
    return (p -> topo == -1);
}

//verifica se a pilha esta cheia
int isFull(Pilha* p) {
    return (p -> topo == max - 1);
}

//insere um valor na pilha
void push(Pilha* p, int valor) {
    if(!isFull(p)) {
        p -> itens[++(p -> topo)] = valor;
    } else {
        printf("Erro: Pilha cheia!\n");
    }
}

//remove e retorna o valor do topo da pilha
int pop(Pilha* p) {
    if(isEmpty(p)) {
        printf("Erro: pilha vazia!\n");
        return -1;//Retorno de erro
    } else {
        return p -> itens[(p -> topo)--];
    }
}

//retorna o valor do topo sem remover
int top(Pilha *p) {
    if(isEmpty(p)) {
        printf("Erro: Pilha vazia\n");
        return -1;
    } else {
        return p -> itens[p->topo];
    }
}

//Programa principal o main
int main() {

    Pilha p;
    initializaStack(&p);
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Topo da pilha: %d\n", top(&p));
    printf("Removido: %d\n", pop(&p));

    printf("Topo da pilha apos remocao: %d\n", top(&p));
    printf("Removido %d\n", pop(&p));

    printf("Topo da pilha apos remocao: %d\n", top(&p));
    return 0;
}
