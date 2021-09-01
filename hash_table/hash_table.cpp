#include <iostream>
#include <stdio.h>

class Node {
    public:
        int data;
        Node* next;
        Node(int fata, Node* next);
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
        int search_and_remove(int data);
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
    for(tmp = linkedList; tmp->next != NULL; tmp = tmp->next) {};
    int tmpInt = tmp->data;
    
    Node* tmp2;
    for(tmp2 = linkedList; tmp2->next != tmp; tmp2 = tmp2->next) {};
    tmp2->next = NULL;

    delete tmp;
    return tmpInt;
}

int LinkedListInt::search_and_remove(int data) { 
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

class HashTable{
    private:
        static const int slots = 8;
        LinkedListInt* arr[slots];
    
    public:
        HashTable();
        void add(int data);
        int find(int data);
        int remove(int data);
        void clean();
        static int hash(int data);
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

    if(arr[slot] == NULL)
        arr[slot] = new LinkedListInt(data);
    else
        arr[slot]->add(data);
}

int HashTable::find(int data) {
    int slot = hash(data);

    //arr[slot]->

}

HashTable::~HashTable() {
    delete *arr;
}

////////////////////////////// buggy

void print_array(int arr[]) {
    for(int i = 0; i<8; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    // int hash;
    // int arr[N];

    // print_array(arr);

    // for(int i = 0; i<N; i++) {
    //     hash = i/N;
    //     arr[hash]++;
    // }

    // print_array(arr);

    HashTable* tab = new HashTable();
    tab->add(1);

}