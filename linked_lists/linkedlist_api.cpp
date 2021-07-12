#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

class LinkedListInt {
    private:
        Node* linkedList;
    
    public:
        LinkedListInt(Node* linkedList);
        void add();
        void pop();
        void tail();
        void head();
        void remove();
        void clean();
        void invert();                
};

LinkedListInt::LinkedListInt(Node* linkedList) : linkedList(linkedList){}

Node createNode(int data, Node* next) {
    return {data, next};
}

Node* linkedList(){

}


int main() {
    Node* head = NULL;


	for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
		printf("%d\n", tmp->data);
	}
}