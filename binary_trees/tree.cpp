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

Node* add_tree(Node* top, int data) {
    Node* newNode = create_node(data);

    if(top == NULL) {
        top = newNode;
    }else{
        if(data < top->data) {
            top->left = add_tree(top->left, data);
            puts((char*)data);
        }else {
            top->right = add_tree(top->right, data);
            puts((char*)data);
        }
    }

    return top;
}

int main() {
    
    Node* top = NULL;

    top = add_tree(top, 42);
    top = add_tree(top, 34);
    top = add_tree(top, 34);
    top = add_tree(top, 73);
    top = add_tree(top, 12);
    top = add_tree(top, 9);
    top = add_tree(top, 87);
    top = add_tree(top, 50);
    top = add_tree(top, 99);
    top = add_tree(top, 63);
    top = add_tree(top, 25);

    printf("%ld\n", sizeof(*top));

    // pre-order travel
    // in-order
    // post-order       

    // one makes this to be a binery search tree


}