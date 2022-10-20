#include <iostream>
#include <vector>
#include <fstream>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printarray(int arr[], int n){
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char** argv) {

    std::string loc = argv[1];
    
    std::vector <int> v;
    std::ifstream file(loc);
    
    if (file) {        
        int value;
        while ( file >> value ) 
            v.push_back(value);
    }
    file.close ();

    int n = v.size();
    int arr[n]; 

    for (int i = 0; i < n; i++) 
        arr[i] = v[i];
    
    printarray(arr, n);

    heapSort(arr, n);

    printarray(arr, n);
}