#include <iostream>
#include <vector>

class MaxHeap {
    std::vector<int> m_heap;

    void heapifyUp(int index) {
        if (index == 0) return; // Root node
        int parentIndex = (index - 1) / 2;
        if (m_heap[index] > m_heap[parentIndex]) {
            std::swap(m_heap[index], m_heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

public:
    void insert(int value) {
        m_heap.push_back(value);
        heapifyUp(m_heap.size() - 1);
    }

    void printHeap() {
        for (int val : m_heap) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MaxHeap heap;
    heap.insert(50);
    heap.insert(80);
    heap.insert(60);
    heap.insert(70);
    heap.insert(30);
    heap.insert(40);
    heap.printHeap(); // Output: 80 70 60 50 40 30
    return 0;
}
