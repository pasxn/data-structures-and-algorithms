#include <iostream>
#include <chrono>
#include <fstream>

long long fibonacci(long long n) {
    if(n<=2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    std::ofstream file("time.txt");

    auto start = std::chrono::system_clock::now();

    int in;
    std::cout << "Enter: ";
    std::cin >> in;
    
    for(int i=1; i<=in; i++) {
        std::cout << "fibonacci: " << fibonacci(i) << std::endl; // task 1
    
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        file << elapsed.count() << std::endl; // s
        
    }

    file.close();
}