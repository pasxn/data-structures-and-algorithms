#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {
  Node* head = NULL;
	Node n1 = {1, NULL};
	Node n2 = {2, NULL};
	Node n3 = {3, NULL};
	Node n4 = {4, NULL};

	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = NULL;

	for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
		printf("%d\n", tmp->data);
	}
}