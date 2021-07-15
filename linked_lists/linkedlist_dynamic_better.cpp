#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    
    Node* tmp = NULL;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    
    return tmp;
}

Node* linkedList(int data, Node* head) {
    Node* newNode = createNode(data); 

    if(head == NULL) {
        head = newNode;
    }else{
        static Node* loc;
        
        if (head->next == NULL)
            loc = head;

        Node* tmp;
        for(tmp = loc; tmp->next != NULL; tmp = tmp->next);
        // moves the tmp pointer to the next pointer of the last attached node
        tmp->next = newNode;
        loc = tmp;
    }

    return head;
}

void printList(Node* head) {
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("%d\n", tmp->data);
	}
}

int main() {
    Node* head = NULL;                   

    head = linkedList(1, head);
    head = linkedList(2, head);
    head = linkedList(3, head);
    head = linkedList(4, head);
    head = linkedList(5, head);
    head = linkedList(6, head);
    head = linkedList(7, head);
    head = linkedList(8, head);
    head = linkedList(9, head);

    printList(head);
}