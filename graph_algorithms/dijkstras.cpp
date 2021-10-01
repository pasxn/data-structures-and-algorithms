#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define LEN 30

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

// for the graph
typedef struct vertex {
    char node_name;
    char visited;
    int cost;
    struct vertex *next;
} Vertex;

// for dijkstras graph
typedef struct row {
    char node_name;
    int dist;
    char prev;
} Row;

void add_vertex(char vertex);
void add_ud_edge(char v1, char v2, int cost);
void add_d_edge(char v1, char v2, int cost);
void add_to_list(Vertex *ptr, char vertex, int cost);
void print_graph(Vertex adj_list[]);
int lookup(char start);
void dijkstras(char from, char to);

Vertex adj_list[LEN];
int num_vertices = 0;

int main() {
    /*
    add_vertex('A');
    add_vertex('B');
    add_vertex('C');
    add_vertex('D');
    add_vertex('E');
    add_vertex('F');
    add_vertex('G');

    add_d_edge('A', 'B', 6);
    add_d_edge('A', 'C', 2);
    add_d_edge('A', 'D', 16);
    add_d_edge('B', 'D', 5);
    add_d_edge('B', 'E', 4);
    add_d_edge('C', 'F', 5);
    add_d_edge('C', 'B', 16);
    add_d_edge('C', 'E', 3);
    add_d_edge('D', 'G', 3);
    add_d_edge('E', 'D', 4);
    add_d_edge('E', 'G', 10);
    add_d_edge('F', 'G', 1);
    */
    
    add_vertex('A');
    add_vertex('B');
    add_vertex('C');
    add_vertex('D');
    add_vertex('E');

    add_d_edge('A', 'B', 7);
    add_d_edge('A', 'C', 1);
    add_d_edge('B', 'C', 3);
    add_d_edge('B', 'D', 3);
    add_d_edge('B', 'E', 2);
    add_d_edge('C', 'D', 1);
    add_d_edge('D', 'E', 5);
    

    print_graph(adj_list);

    dijkstras('A', 'G');

}

void dijkstras(char from, char to) {
    Row table[LEN];

    for(int i = 0; i<LEN; i++) {
        table[i].node_name = adj_list[i].node_name;
        table[i].prev = 'A';

        if(table[i].node_name == from)
            table[i].dist = 0;
        else
            table[i].dist = INT_MAX;
    }

    Row *current_vertex = (Row*)malloc(sizeof(Row));
    current_vertex->dist = INT_MAX;
    
    int j = 0;
    while(j < num_vertices) {
        for(int i = 0; table[i].node_name != 0; i++) {
            if(table[i].dist <= current_vertex->dist && adj_list[lookup(table[i].node_name)].visited == FALSE) {
                current_vertex = &table[i];
                //printf("%c\n", current_vertex->node_name);
            }
        }

        adj_list[lookup(current_vertex->node_name)].visited = TRUE; 
            
        for(Vertex *tmp = adj_list[lookup(current_vertex->node_name)].next; tmp != NULL; tmp = tmp->next) {
            int distance_from_start = current_vertex->dist + tmp->cost;
            
            int pos = lookup(tmp->node_name); 
            //printf("%d | %d \n", distance_from_start, table[pos].dist);   
            if(distance_from_start <= table[pos].dist) {
                table[pos].dist = distance_from_start;
                table[pos].prev = current_vertex->node_name;
            }
        }
        j++;  
    }

    puts("\n-----------------------------");
    for(int i = 0; table[i].node_name != 0; i++)
        printf("%c |%d |%c \n", table[i].node_name, table[i].dist, table[i].prev); 

}

int lookup(char start) {
    for(int i = 0; i<num_vertices; i++) {
        if(start == adj_list[i].node_name)
            return i;
    }
}

void add_vertex(char vertex) {
    adj_list[num_vertices].node_name = vertex;
    adj_list[num_vertices].visited = FALSE;
    adj_list[num_vertices].cost = 0;
    adj_list[num_vertices].next = NULL;
    num_vertices ++;
}

void add_ud_edge(char v1, char v2, int cost) {
    for(int i=0; i<num_vertices  ; i++) {
        if(adj_list[i].node_name == v1) // found the node
            add_to_list(&adj_list[i], v2, cost);
        
        if( adj_list[i].node_name == v2 ) // found the node
            add_to_list(&adj_list[i], v1,  cost);
    }
}

void add_d_edge(char v1, char v2, int cost) {
    for(int i=0; i<num_vertices  ; i++) {
        if(adj_list[i].node_name == v1) // found the node
            add_to_list(&adj_list[i], v2, cost);
    }
}

void add_to_list(Vertex *ptr, char vertex, int cost) {
    Vertex *tmp;
    // move to end of current list
    for(tmp=ptr; tmp->next != NULL; tmp=tmp->next);
    
    tmp->next = (Vertex*)malloc(sizeof(Vertex));
    (tmp->next)->node_name = vertex;
    (tmp->next)->visited = FALSE;
    (tmp->next)->cost = cost;
    (tmp->next)->next = NULL;
}

void print_graph(Vertex adj_list[]) {
    Vertex *tmp;

    for(int i=0; i < num_vertices; i++) {
        printf("[%c] ", adj_list[i].node_name);
        for(tmp=adj_list[i].next; tmp != NULL; tmp=tmp->next)
            printf("->(%c: %d)", tmp->node_name, tmp->cost);

        printf("\n");
    }
}