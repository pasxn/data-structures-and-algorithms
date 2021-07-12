#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    
    Node* tmp = NULL;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    
    return tmp;
}

void linkedList(int data) {
    Node* newNode = NULL;
    newNode = createNode(data); 

    if(head == NULL) {
        head = newNode;
    }else{
        Node* tmp;
        for(tmp = head; tmp->next != NULL; tmp = tmp->next);
        // moves the tmp pointer to the next pointer of the last attached node

        tmp->next = newNode;
    }
}

void printList() {
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
		printf("%d\n", tmp->data);
	}
}

int main() {
    linkedList(1);
    linkedList(2);
    linkedList(3);

    printList();
}