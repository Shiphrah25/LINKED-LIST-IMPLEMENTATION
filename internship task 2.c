#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct LinkedList {
    Node* head;
} LinkedList;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        printf("Memory error\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}
void insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
}
void insertAtEnd(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteNode(LinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    Node* temp = list->head;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}
void traverseList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void freeList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}
int main() {
    LinkedList* list = createLinkedList();

    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);
    insertAtBeginning(list, 5);

    printf("List: ");
    traverseList(list);

    deleteNode(list, 20);

    printf("List after deletion: ");
    traverseList(list);

    freeList(list);

    return 0;
}
