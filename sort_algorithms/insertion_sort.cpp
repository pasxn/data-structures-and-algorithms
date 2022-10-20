#include <iostream>
#include <vector>
#include <fstream>

/* Function to sort an array using insertion sort*/
void insertionsort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    insertionsort(arr, n);

    printarray(arr, n);
}