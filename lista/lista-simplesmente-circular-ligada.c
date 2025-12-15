//Implementa��o de Lista Circular Ligada Din�mica

#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da lista circular
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da lista circular
typedef struct {
    Node* head;
} CircularLinkedList;

// Fun��o para inicializar a lista
void initializeList(CircularLinkedList* list) {
    list->head = NULL;
}

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro de alocacao de memoria\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode;  // O n� aponta para si mesmo
    return newNode;
}

// Fun��o para inserir um n� no in�cio da lista
void insertAtBeginning(CircularLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {  // Se a lista estiver vazia
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = list->head;
        list->head = newNode;
    }
}

// Fun��o para inserir um n� no final da lista
void insertAtEnd(CircularLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {  // Se a lista estiver vazia
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = list->head;
    }
}

// Fun��o para remover um n� do in�cio da lista
void removeFromBeginning(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Erro: Lista esta vazia!\n");
        return;
    }
    Node* temp = list->head;
    if (temp->next == list->head) {  // Se houver apenas um n�
        free(temp);
        list->head = NULL;
    } else {
        Node* last = list->head;
        while (last->next != list->head) {
            last = last->next;
        }
        list->head = list->head->next;
        last->next = list->head;
        free(temp);
    }
}

// Fun��o para remover um n� do final da lista
void removeFromEnd(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Erro: Lista esta vazia!\n");
        return;
    }
    Node* temp = list->head;
    if (temp->next == list->head) {  // Se houver apenas um n�
        free(temp);
        list->head = NULL;
    } else {
        Node* prev = NULL;
        while (temp->next != list->head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = list->head;
        free(temp);
    }
}

// Fun��o para buscar um valor na lista circular
Node* search(CircularLinkedList* list, int value) {
    if (list->head == NULL) {
        return NULL;
    }
    Node* temp = list->head;
    do {
        if (temp->data == value) {
            return temp;  // Valor encontrado
        }
        temp = temp->next;
    } while (temp != list->head);
    return NULL;  // Valor n�o encontrado
}

// Fun��o para exibir a lista circular
void displayList(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Lista esta vazia.\n");
        return;
    }
    Node* temp = list->head;
    printf("Lista Circular: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

// Programa principal
int main() {
    CircularLinkedList list;
    initializeList(&list);

    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);
    displayList(&list);

    insertAtBeginning(&list, 5);
    displayList(&list);

    removeFromBeginning(&list);
    displayList(&list);

    removeFromEnd(&list);
    displayList(&list);

    // Busca um valor na lista
    int valueToSearch = 20;
    Node* searchResult = search(&list, valueToSearch);
    if (searchResult != NULL) {
        printf("Valor %d encontrado na lista.\n", valueToSearch);
    } else {
        printf("Valor %d nao encontrado na lista.\n", valueToSearch);
    }

    return 0;
}

