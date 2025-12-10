//Cabeçalho da linguagme c estrutura de dados
#include "cstdio"
#include "cstdlib"
#include "cstring"

#define MAX 100
#define MAX_NOME 50

//-------------------- estrutura do ingresso --------------------
typedef struct {
    int numeroIngresso; //Numero unico do ingresso
    char Comprador[MAX_NOME];
    char setor[MAX_NOME]; //popular, cativa, VIP
    int tipo; //1 = inteiro , 2 = Meia
    float preco;
} Ingresso;

/* -------------------- limpar buffer --------------------
 * Função: limpar buffer
 * Descrição: limpa o buffer do teclado para eveitar problema com fgets apos o scanf
 * Parametros: nenhuma
 * retorna: void
*/
void limparBuffer(){
    int c;
    while((c = getchar())  != '\n' && c != EOF);
}

// -------------------- pilha(historico de vendas) --------------------
typedef struct {
    Ingresso vendas[MAX];
    int topo;
}Pilha;

/*
 * Função: inicializa pilha
 * Descrição: inicializa a pilha do historico de vendas
 * Parametros: p - ponteiros para  a pilha
 * Retorna: void
 * */
void inicializaPilha(Pilha *p){
    p -> topo = -1;
}

/*
 * Função: pilha vazia
 * Descrição: verifica se a pilha está vazia
 * Parametros: p-> ponteiros para a pilha
 * retorna 1 se esta vazia, 0 contrario
 * */
int pilhaVazia(Pilha* p){
    return p -> topo == -1;
}

/*
 * Função: pilha vazia
 * Descrição: verifica se a pilha está cheia
 * Parametros: p -> ponteiros para a pilha
 * retorna 1 se esta vazia, 0 contrario
 */
int pilhaCheia(Pilha *p){
    return p -> topo == MAX - 1;
}

/*
 * Função: push
 * Descrição: adiciona um ingresso ao topo da pilha
 * Parametros: p -> ponteiros para a pilha, ing - ingresso a ser adicionado
 * Retorna: void
 * */
void push(Pilha *p, Ingresso ing){
    if(pilhaCheia(p)){
        printf("Historico cheio\n");
        return;
    }
    p -> topo++;
    p -> vendas[p -> topo] = ing;
}

/*
 * Função: pop
 * Descrição: Remove e retorne o ingresso o topo da pilha
 * Parametros: p -> ponteiros para a pilha
 * Retorna: ingresso removido ou ingresso vazio se pilha vazia
 * */
Ingresso pop(Pilha* p){
    Ingresso vazio;
    vazio.numeroIngresso = -1;
    if(pilhaCheia(p)){
        printf("Historico vazio\n");
        return vazio;
    }
    return p -> vendas [p -> topo--];
}

/*
 * Função: mostrar historico
 * Descrição: mostra todos os ingressos vendidos no historico da pilha
 * Parametros: p -> ponteiros para a pilha
 * Retorna: void
 * */
void mostarHistorico(Pilha *p){
    if(pilhaCheia(p)){
        printf("Historico vazio\n");
        return;
    }
    printf("\n--- Historico de vendas ---\n");
    for(int i = p-> topo; i >= 0; i++){
        printf("Numeros: %d | Comprador: %s | Setor: %s | Tipo: %s | Preco: %.2f\n",
               p -> vendas[i].numeroIngresso,
               p -> vendas[i].Comprador,
               p -> vendas[i].setor,
               p -> vendas[i].tipo == 1 ? "Inteira" : "Meia",
               p -> vendas[i].preco);
    }
}

//-------------------- Fila compradores --------------------
typedef struct {
    Ingresso compradores[MAX];
    int inicio, fim;
}Fila;

/*
 * Função: inicializa fila
 * Descrição: inicializa a fila de compradores
 * Parametros: f -> ponteiros para a fila
 * Retorna: void
 * */
void inicializaFila(Fila *f) {
    f -> inicio = 0; f -> fim = 0;
}

/*
 * Função: fila Vazia
 * Descrição: Verifica se a fila esta vazia
 * Parametros: f -> ponteiros para a fila
 * Retorna: 1 se vazia, 0 caso contrario
 * */
int filaVazia(Fila *f) {
    return f -> inicio == f -> fim;
}

/*
 * Função: inicializa fila
 * Descrição: Verifica se a fila esta cheia
 * Parametros: f -> ponteiros para a fila
 * Retorna: 1 se vazia, 0 caso contrario
 * */
int filaCheia(Fila *f) {
    return f -> inicio == f -> fim;
}

/*
 * Função: infileirar
 * Descrição: adicionar um comprador ao final do fila.
 * Parametros: f -> ponteiros para a pilha, ing - ingresso do comprador
 * Retorna: void
 * */
void enfileirar(Fila *f, Ingresso ing){
    if(filaCheia(f)){
        printf("Fila cheia\n");
        return;
    }
    f -> compradores[f -> fim] = ing;
    f -> fim = (f -> fim + 1) % MAX;
}

/*
 * Função: desenfileirar
 * Descrição: Remove a retorna o primeiro comprador da fila
 * Parametros: f - ponteiros para a pilha
 * Retorna: ingresso do comprador ou ingresso vazio se fila esta vazia
 * */
Ingresso desenfileira(Fila *f){
    Ingresso vazio; vazio.numeroIngresso = -1;
    if(filaVazia(f)){
        printf("Fila vazia!\n");
        return vazio;
    }
    Ingresso ingresso = f -> compradores[f -> inicio];
    f -> inicio = (f -> inicio + 1) % MAX;
    return ingresso;
}

/*
 * Função mostrar fila
 * Descrição: Mostra todos os compradores na fila
 * Parâmetros: f - ponteiro para a fila
 * Retorna: void
 * */
void mostrarFila(Fila *f){
    if(filaVazia(f)){
        printf("Fila vazia");
        return;
    }
    printf("\n--- Fi;a de Compradores ---\n");
    int i = f -> inicio;
    while(i != f -> fim){
        printf("Numero: %d | Comprador: %s | Setor: %s | Tipo: %s | Preco: %.2f\n",
               f -> compradores[i].numeroIngresso,
               f -> compradores[i].Comprador,
               f -> compradores[i].setor,
               f -> compradores[i].tipo == 1 ? "Inteira" : "Meia",
               f -> compradores[i].preco);
        i = (i + 1) % MAX;
    }
}

//-------------------- Lista Ligada (Ingressos Vendidos) --------------------
typedef struct No{
    Ingresso ing;
    struct No *prox;
}No;

No* lista = NULL;

/*
 * Função: inserirLista
 * Descrição: insere um ing vendido no início da lista ligada
 * Parâmetros: ing - ing a ser inserido
 * Retorna: void
 * */
void inserirLista(Ingresso ing){
    No *novo = (No*) malloc(sizeof (No));
    if(novo == NULL){
        printf("Erro de memoria! Nao foi possivel inserir ingresso.\n");
        return;
    }
    novo -> ing = ing;
    novo -> prox = lista;
    lista = novo;
}

/*
 * Função: romover lista
 * Descrição: Remove um ingresso vendido da lista pelo número do ingresso
 * Parâmetros: numeroIngresso - Número do ingresso a ser removido
 * Retorna: void
 * */
void removerLista(int numeroIngresso){
    No *atual = lista, *anterior = NULL;
    while(atual != NULL){
        if(atual -> ing.numeroIngresso == numeroIngresso){
            if(anterior == NULL)
                lista = atual -> prox;
            else
                anterior -> prox = atual -> prox;
            free(atual);
            printf("Ingresso removido.\n");
            return;
        }
        anterior = atual;
        atual = atual -> prox;
    }
    printf("Ingresso nao encontrado.\n");
}

/*
 * Função: mostrar lista
 * Descrição: mostra todos os ingressos vendidos na lista ligada.
 * Parâmetros: nenhum
 * retorna: void
 * */
void mostrarLista(){
    if(lista == NULL){
        printf("Nenhuma ingresso vendido.\n");
        return;
    }
    printf("\n--- Ingresso vendido ---\n");
    No *atual = lista;
    while(atual != NULL){
        printf("Numero: %d | Comprador: %s | Setor: %s | tipo: %s | Preco: %.2f\n",
               atual ->ing.numeroIngresso,
               atual ->ing.Comprador,
               atual ->ing.setor,
               atual ->ing.tipo == 1 ? "Inteira" : "Meia",
               atual ->ing.numeroIngresso);
        atual = atual -> prox;
    }
}

//-------------------- Cadastro do Ingresso --------------------
/*
 * Função: criarIngresso
 * Descrição: Cria e preenche os dados de um ingresso.
 * Parâmetros: nenhum
 * Retorna: ingresso preenchido
 * */

Ingresso criarOngresso(){
    Ingresso ingresso;
    int opcao;

    printf("Numero do ingresso: ");
    if(scanf("%d", &ingresso.numeroIngresso) != 1){
        printf("Entrada invalida! Numero de ingresso deve ser inteiro.\n");
        limparBuffer();
        ingresso.numeroIngresso = -1;
        return ingresso;
    }
    limparBuffer();
    printf("Nome do comprador: ");
    if(fgets(ingresso.Comprador, MAX_NOME, stdin) == NULL){
        printf("Erro ao ler nome do comprador.\n");
        strcpy(ingresso.Comprador, "Desconhecidos");
    }
    ingresso.Comprador[strcspn(ingresso.Comprador, "\n")] = 0;

    do{
        printf("Setor (1 = popular) (1=Popular (I=R$50 / M=R$25), 2=Cativa (I=R$100 / M=R$50), 3=VIP (I=R$300 / M=R$150)): ");
        if(scanf("%d", &opcao) != 1){
            printf("Entrada invalida! Digite um numero: .\n");
            limparBuffer();
            opcao = 0;
            continue;
        }

    }while(opcao < 1 || opcao > 3);
}

int main(){}
