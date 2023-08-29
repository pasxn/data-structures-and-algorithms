#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
  // Creating nodes
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);

  // Connecting nodes
  node1->next = node2;
  node2->next = node3;

  // Traversing linked list and printing values
  ListNode *current = node1;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }

  // Clean up memory
  delete node1;
  delete node2;
  delete node3;

  return 0;
}
