#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;

// Function to initialize the heap
void initHeap(MaxHeap* heap)
{
    heap->size = 0;
}

// Function to swap two elements
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up to maintain max-heap property after insertion
void heapifyUp(MaxHeap* heap, int index)
{
    if (index == 0) return; // Root node
    int parentIndex = (index - 1) / 2;
    if (heap->data[index] > heap->data[parentIndex]) {
        swap(&heap->data[index], &heap->data[parentIndex]);
        heapifyUp(heap, parentIndex);
    }
}

// Function to insert an element into the heap
void insert(MaxHeap* heap, int value)
{
    if (heap->size == MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    heap->data[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Function to print the heap
void printHeap(const MaxHeap* heap)
{
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main()
{
    MaxHeap heap;
    initHeap(&heap);

    insert(&heap, 40);
    insert(&heap, 70);
    insert(&heap, 80);
    insert(&heap, 50);
    insert(&heap, 60);
    insert(&heap, 30);

    printHeap(&heap); // Output: 80 70 60 50 40 30

    return 0;
}
