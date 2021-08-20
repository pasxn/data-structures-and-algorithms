#include <iostream>
#include <vector>
#include <fstream>

/* function to sort arr using shellSort */
void shellSort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1) {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
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

    shellSort(arr, n);

    printarray(arr, n);
}