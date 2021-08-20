#include <stdio.h>

#define N 10

void print_array(int arr[]) {
    for(int i = 0; i<N; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int hash;
    int arr[N];

    print_array(arr);

    for(int i = 0; i<N; i++) {
        hash = i/N;
        arr[hash]++;
    }

    print_array(arr);
}