
// EN20421380 Perera R.P.S

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
    struct node* next;
} Node;

Node* createNode(int x, int y);
void push(int x, int y, Node** head);
Node* pop(Node** stack);
void print_stack(Node* head);

void main(void) {
    Node* stack = NULL;

    push(1, 1, &stack);      // passing the Node* by referance to manipulate
    push(2, 2, &stack);
    push(3, 3, &stack);
    push(4, 4, &stack);
    push(5, 5, &stack);
    push(6, 6, &stack);

    puts("--------------------------- printing the stack -----------------------------");
    print_stack(stack);
    puts("----------------------------------------------------------------------------\n");

    Node* node_ptr = pop(&stack);
    printf("Values of the popped Node: %d, %d\n\n", node_ptr->x, node_ptr->y);

    puts("-------------- printing the stack after popping the top Node ---------------");
    print_stack(stack);

    free(stack);
}

void push(int x, int y, Node** head) {
    Node* newNode = createNode(x, y); 

    if(*head == NULL) {      // Manipulating the pointer passed as a referance
        *head = newNode;     
    }else{
        newNode->next = *head;
        *head = newNode;
    }
}

Node* pop(Node** stack) {   // using a pointer to pointer
    Node* deref = *stack;   // dereferencing for the ease of use
    Node* tmp = createNode(deref->x,  deref->y); 
    // copying the values of the 1st node of the stack to return

    *stack = deref->next;   
    // manipulating the stack passed by a referance and deleting the 1st node

    return tmp;
}

Node* createNode(int x, int y) { 
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->x = x;
    tmp->y = y;
    tmp->next = NULL;
    
    return tmp;
}

void print_stack(Node* head) {
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next) {
        printf("%d, %d\n", tmp->x, tmp->y);
    }
}