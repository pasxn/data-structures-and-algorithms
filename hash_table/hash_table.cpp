#include <iostream>
#include <stdio.h>

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
        int search(int data);
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

int LinkedListInt::search(int data) { 
    Node* tmp;
    int isThere = 0;
    for(tmp = linkedList; tmp->next != NULL; tmp = tmp->next) {
        if(tmp->data == data) {
            isThere = 1;
            break;
        }
    };

    return isThere;
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
		printf("%d  ", tmp->data);
	}
}

LinkedListInt::~LinkedListInt() {
    delete linkedList;
}

class HashTable{
    private:
        static const int slots = 5;
        LinkedListInt* arr[slots];
    
    public:
        HashTable();
        void add(int data);
        int isThere(int data);
        void clean();
        int hash(int data);
        void print();
        ~HashTable();
};

HashTable::HashTable(){
    for(int i = 0; i<slots; i++) {
        arr[i] = NULL;
    }
};

int HashTable::hash(int data) {
    return data%slots;
}

void HashTable::add(int data) {
    int slot = hash(data);

    std::cout << slot << std::endl;

    if(arr[slot] == NULL)
        arr[slot] = new LinkedListInt(data);
    else
        arr[slot]->add(data);
}

int HashTable::isThere(int data) {
    int slot = hash(data);

    return arr[slot]->search(data);
}

void HashTable::clean(){
    for(int i = 0; i<slots; i++) {
        arr[i]->clean();
    }
}

void HashTable::print() {
    for(int i = 0; i<slots; i++) {
        printf("array slot [%d]\n", i);
        arr[i]->print();
        puts("\n\n");
    }
}

HashTable::~HashTable() {
    delete *arr;
}

int main() {

    HashTable* tab = new HashTable();
    
    for(int i = 1; i<=10; i++) {
        tab->add(i);
    }

    tab->print();

    delete tab;

}