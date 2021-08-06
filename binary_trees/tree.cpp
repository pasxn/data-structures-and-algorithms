#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* right;
    struct node* left;
} Node;

Node* create_node(int data) {
    Node* tmp;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

void add_tree(Node** top, int data) {
    if(*top == NULL) {
        Node* newNode = create_node(data);
        *top = newNode;
    }else{
        if(data < (*top)->data)
            add_tree( &((*top)->left) , data);
        else
            add_tree( &((*top)->right), data);
    }
}

void print_tree(Node* top) {
    if(top == NULL) 
        return;
    print_tree(top->left);
    printf("%d\n", top->data);
    print_tree(top->right);
}

int main() {
    
    Node* top = NULL;

    add_tree(&top, 42); // use pointer to pointer
    add_tree(&top, 34);
    add_tree(&top, 73);
    add_tree(&top, 12);
    add_tree(&top, 9);
    add_tree(&top, 87);
    add_tree(&top, 50);
    add_tree(&top, 98);
    add_tree(&top, 63);
    add_tree(&top, 25);
    add_tree(&top, 99);
    
    print_tree(top);
    add_tree(&top, 69);
    print_tree(top);
}


/*
Node* add_tree(Node* top, int data) {
    if(top == NULL) {
        Node* newNode = create_node(data);
        top = newNode;
    }else{
        if(data < top->data) {
            top->left = add_tree(top->left, data);
            return top;
        }else {
            top->right = add_tree(top->right, data);
            return top;
        }
    }

    return top;
}
*/