
// EN20421380 Perera R.P.S

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
    struct node* next;
} Node;

Node* createNode(int x, int y);
Node* addQ(int x, int y, Node* front);
Node* removeQ(Node** queue);
void print_Queue(Node* front);


void main(void) {
    Node* queue = NULL;   

    queue = addQ(1, 1, queue);
    queue = addQ(2, 2, queue);
    queue = addQ(3, 3, queue);
    queue = addQ(4, 4, queue);
    queue = addQ(5, 5, queue);
    queue = addQ(6, 6, queue); 

    puts("--------------------------- printing the queue -----------------------------");
    print_Queue(queue);
    puts("----------------------------------------------------------------------------\n");

    Node* node_ptr = removeQ(&queue);
    printf("Values of the removed Node: %d, %d\n\n", node_ptr->x, node_ptr->y);

    puts("-------------- printing the queue after popping the top Node ---------------");
    print_Queue(queue);
    
    free(queue);
}

Node* removeQ(Node** queue) {   // using a pointer to pointer
    Node* deref = *queue;   // dereferencing for the ease of use
    Node* tmp = createNode(deref->x,  deref->y); 
    // copying the values of the 1st node of the queue to return

    *queue = deref->next;   
    // manipulating the queue passed by a referance and deleting the 1st node

    return tmp;

}

Node* addQ(int x, int y, Node* front) {
    Node* newNode = createNode(x, y); 

    if(front == NULL) {
        front = newNode;
    }else{
        static Node* loc;
        
        if (front->next == NULL)
            loc = front;

        Node* tmp;
        for(tmp = loc; tmp->next != NULL; tmp = tmp->next);
        // moves the tmp pointer to the next pointer of the last attached node
        tmp->next = newNode;
        loc = tmp;
    }

    return front;
}

Node* createNode(int x, int y) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->x = x;
    tmp->y = y;
    tmp->next = NULL;
    
    return tmp;
}

void print_Queue(Node* front) {
    for(Node* tmp = front; tmp != NULL; tmp = tmp->next) {
        printf("%d, %d\n", tmp->x, tmp->y);
    }
}