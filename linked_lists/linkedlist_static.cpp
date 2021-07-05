#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {
    Node* head;
    Node n1 = {1, NULL};
    Node n2 = {2, NULL};
    Node n3 = {3, NULL};

    head = &n1;
    n1.next = &n2;
    n2.next = &n3;

    Node* tmp;
    tmp = head;
    while ((*tmp).next != NULL) {      // do not go inside when tmp = last node
        printf("%d\n", tmp->data);     // because lastnode.next = NULL
        tmp = tmp->next;
    }

    printf("%d\n", tmp->data); 
}