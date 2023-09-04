#include <iostream>

struct Node {
  int data;
  Node* next;

  Node(int data, Node* next) : data(data), next(next) {}

};

void print(Node* tmp) {
  for (tmp; tmp != NULL; tmp = tmp->next) {
    std::cout << tmp->data << std::endl;
  }

  printf("-----------------------------------\n");
}

Node* r1(Node* head) {
  Node* p;
  Node* c;
  Node* n;

  p = NULL;
  c = head;
  n = head->next;

  while (n != NULL) {
    c->next = p;
    p = c;
    c = n;
    n = n->next;
  }

  c->next = p;
  head = c;

  return head;
}

Node* r2(Node* head) {
  Node* p = NULL;
  Node* n;

  while (head != NULL) {
    n = head->next;
    head->next = p;
    p = head;
    head = n;
  }

  return p;
}

int main() {

  Node* ll = new Node(0, new Node(1, new Node(2, new Node(3, new Node(4, NULL)))));

  print(ll);
  ll = r1(ll);
  print(ll);
  ll = r2(ll);
  print(ll);

}
