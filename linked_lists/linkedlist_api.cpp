#include <iostream>

class Node {
    public:
        int data;
        Node* next;
        Node(int data, Node* next);
        ~Node();
};

Node::Node(int data, Node* next) : data(data), next(next) {};
Node::~Node() {};

class LinkedListInt {
    private:
        Node* linkedList;
    
    public:
        LinkedListInt(int data); 
        void add(int data); 
        int pop();
        int tail(); 
        int head(); 
        void clean(); 
        void modifyHead(int data); 
        void print(); 
        ~LinkedListInt(); 

};

LinkedListInt::LinkedListInt(int data) {
    linkedList = new Node(data, NULL);
}

void LinkedListInt::add(int data) {
    static Node* loc;
    
    if (linkedList->next == NULL)
            loc = linkedList;    
    
    Node* tmp;
    for(tmp = loc; tmp->next != NULL; tmp = tmp->next) {};
    tmp->next = new Node(data, NULL);
    loc = tmp;
}

int LinkedListInt::pop() { 
    Node* tmp;
    for(tmp = linkedList; tmp->next != NULL; tmp = tmp->next) {};
    int tmpInt = tmp->data;
    
    Node* tmp2;
    for(tmp2 = linkedList; tmp2->next != tmp; tmp2 = tmp2->next) {};
    tmp2->next = NULL;

    delete tmp;
    return tmpInt;
}

int LinkedListInt::tail() {
    Node* tmp;
    for(tmp = linkedList; tmp->next != NULL; tmp = tmp->next) {};
    return tmp->data;
}

int LinkedListInt::head() {
    return linkedList->data;
}

void LinkedListInt::clean() {
    delete linkedList->next;
    linkedList->next = NULL;
    linkedList->data = 0;
}

void LinkedListInt::modifyHead(int data) {
    linkedList->data = data;
}

void LinkedListInt::print() {
    for(Node* tmp = linkedList; tmp != NULL; tmp = tmp->next){
		printf("%d\n", tmp->data);
	}
}

LinkedListInt::~LinkedListInt() {
    delete linkedList;
}


int main() {
    LinkedListInt* ll = new LinkedListInt(1);
    ll->add(2);
    ll->add(3);
    ll->add(4);
    ll->add(5);
    ll->add(6);
    ll->add(7);
    ll->add(8);

    ll->print();

    ll->clean();

    ll->print();

    ll->modifyHead(5);

    ll->print();   
        
    std::cout << ll->pop() <<std::endl;

    ll->print();

    std::cout << ll->pop() <<std::endl;

    ll->print();

    delete ll;

}