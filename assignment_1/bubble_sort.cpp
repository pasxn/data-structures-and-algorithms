#include <iostream>
#include <vector>
#include <fstream>

// an optimized version of Bubble Sort
void bubblesort(int arr[], int n) {
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  
            }
        }
        // if no two elements were swapped by inner loop, then break
        if (swapped != 1)
                break;
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

    bubblesort(arr, n);

    printarray(arr, n);
} 