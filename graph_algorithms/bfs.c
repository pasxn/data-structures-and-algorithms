#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// for the graph
typedef struct vertex {
    char node_name;
    char visited;
    struct vertex *next;
} Vertex;

// for the queue
typedef struct node {
    char x;
    struct node* next;
} Node;

void add_vertex(char vertex);
void add_ud_edge(char v1, char v2);
void add_d_edge(char v1, char v2);
void add_to_list(Vertex *ptr, char vertex);
void print_graph(Vertex adj_list[]);
Node* createNode(char x);
Node* addQ(char x, Node* front);
Node* removeQ(Node** queue);
void print_Queue(Node* front);
int lookup(char start);
void bfs(char start);

Vertex adj_list[30];
int num_vertices = 0;

int main() {
    add_vertex('A');
    add_vertex('B');
    add_vertex('C');
    add_vertex('D');
    add_vertex('E');
    add_vertex('F');
    add_vertex('G');
    add_vertex('H');
    add_vertex('I');

    add_ud_edge('A', 'B');
    add_ud_edge('A', 'C');
    add_ud_edge('A', 'D');
    add_ud_edge('A', 'E');
    add_ud_edge('B', 'F');
    add_ud_edge('D', 'G');
    add_ud_edge('F', 'H');
    add_ud_edge('G', 'I');
    // add_ud_edge('E', 'H');

    // add_d_edge('I', 'H');

    print_graph(adj_list);
    puts("\n-----------------------------");
    bfs(adj_list[0].node_name); 
    puts("\n");
}

int lookup(char start) {
    for(int i = 0; i<num_vertices; i++)
        if(start == adj_list[i].node_name)
            return i;
}

void bfs(char start) {
    Node* queue = NULL;
    int start_index;
    char output[20];
    int k = 0;

    for(int i = 0; i<20; i++)
        output[i] = 0; 

    start_index = lookup(start);

    output[k] = adj_list[start_index].node_name;
    k++;
    adj_list[start_index].visited = TRUE;

    queue = addQ(adj_list[start_index].node_name, queue);

    while(queue != NULL) {
        Node* v = removeQ(&queue);
        int out_q_index = lookup(v->x);

        for(Vertex* tmp = &adj_list[out_q_index]; tmp != NULL; tmp = tmp->next) {
            if (adj_list[lookup(tmp->node_name)].visited == FALSE) {
                output[k] = tmp->node_name;
                k++;
                queue = addQ(tmp->node_name, queue);
                adj_list[lookup(tmp->node_name)].visited = TRUE;
            }
        }
    }

    for(int j = 0; output[j] != 0; j++) {
        printf("| %c ", output[j]);
    }   
}

void add_vertex(char vertex) {
    adj_list[num_vertices].node_name = vertex;
    adj_list[num_vertices].visited = FALSE;
    adj_list[num_vertices].next = NULL;
    num_vertices ++;
}

void add_ud_edge(char v1, char v2) {
    for(int i=0; i<num_vertices  ; i++) {
        if(adj_list[i].node_name == v1) // found the node
            add_to_list(&adj_list[i], v2);
        
        if( adj_list[i].node_name == v2 ) // found the node
            add_to_list(&adj_list[i], v1);
    }
}

void add_d_edge(char v1, char v2) {
    for(int i=0; i<num_vertices  ; i++) {
        if(adj_list[i].node_name == v1) // found the node
            add_to_list(&adj_list[i], v2);
    }
}

void add_to_list(Vertex *ptr, char vertex) {
    Vertex *tmp;
    // move to end of current list
    for(tmp=ptr; tmp->next != NULL; tmp=tmp->next);
    
    tmp->next = (Vertex*)malloc(sizeof(Vertex));
    (tmp->next)->node_name = vertex;
    (tmp->next)->visited = FALSE;
    (tmp->next)->next = NULL;
}

void print_graph(Vertex adj_list[]) {
    Vertex *tmp;

    for(int i=0; i < num_vertices; i++) {
        printf("[%c] ", adj_list[i].node_name);
        for(tmp=adj_list[i].next; tmp != NULL; tmp=tmp->next)
            printf("->(%c)", tmp->node_name);

        printf("\n");
    }
}

Node* removeQ(Node** queue) {   // using a pointer to pointer
    Node* deref = *queue;   // dereferencing for the ease of use
    Node* tmp = createNode(deref->x); 
    // copying the values of the 1st node of the queue to return

    *queue = deref->next;   
    // manipulating the queue passed by a referance and deleting the 1st node

    return tmp;

}

Node* addQ(char x, Node* front) {
    Node* newNode = createNode(x); 

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

Node* createNode(char x) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->x = x;
    tmp->next = NULL;
    
    return tmp;
}

void print_Queue(Node* front) {
    for(Node* tmp = front; tmp != NULL; tmp = tmp->next) {
        printf("| %c ", tmp->x);
    }
}