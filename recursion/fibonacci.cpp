#include <iostream>
#include <chrono>

long long fibonacci(long long n) {
    // 0 1 2 3 4 5 6 7 8 9
    // 0 1 1 2 3 5 8 13
    if(n<=2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    
}