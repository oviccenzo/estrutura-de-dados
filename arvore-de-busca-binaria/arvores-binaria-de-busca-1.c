//
// Created by Robert L Resende on 09/11/25.
//
#include <cstdio>
#include <cstdlib>

typedef struct No{
    int chaves;
    struct No* esquerda;
    struct No* direita;
}No;

//Função para criar um novo nó da ABB, retorna um ponteiro para o mesmo
No* criaNo(int valor){
    No* novoNo = (No*)mallco(sizoef(No));
    novoNo -> chave = valor;
    novoNo -> esquerda = novoNo -> direita = NULL;
    return novoNo;
}

//Função para inserir um nó na ABB, retorna um ponteiro para a raiz
No* insere(No* raiz, int valor){
    if (raiz == NULL)
        return criaNo(valor);
    if(valor < raiz -> chave){
        raiz -> esquerda = insere(raiz -> esquerda, valor);
        return raiz;
    }
    else
        if(valor > raiz -> chave){
            raiz -> direita = insere(raiz -> direita, valor);
        }
        else//O valor já existe na ABB, somente retornar a raiz
            return raiz;//Retorna a raiz para manter a árvore conectado
}

//Função para busca pela chuva valor na ABB
No* busca(No *raiz, int valor){
    if(raiz == NULL || raiz -> chave == valor)
        return raiz; //Retorna o nó se encontrado ou NULL se não existir
    if(valor < raiz -> chave)
        return busca(raiz -> esquerda, valor);
    else
        return busca(raiz -> direita, valor);
}

//Função auxiliar para encontrar o menor valor em uma subárvore
No* menorValor(No* raiz){
    No* atual = raiz;
    //Enquanto o nó atual não for NULL e
    //possuir um filho a esquerda
    while(atual && atual -> esquerda != NULL)
        atual = atual esquerda;
    return atual;
}

//Função para remover um nó da ABB cuja chave o valor e
//retorna a raiz da ABB atualizado aós a remoção
No* removeNo(No* raiz, int valor){
    if(raiz == NULL)  //caso base: árvore vazia ou nó a ser
        return raiz;  //removido não foi encontrado
    if(valor < raiz -> chave)
}

int main(){
    printf("");
}