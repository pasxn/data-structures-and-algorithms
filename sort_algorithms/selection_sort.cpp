#include <iostream>
#include <vector>
#include <fstream>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionsort(int arr[], int n) {
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
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

    selectionsort(arr, n);

    printarray(arr, n);

}