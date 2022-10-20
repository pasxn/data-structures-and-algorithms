#include <iostream>
#include <chrono>

long long factorial_it(long long a) {
    long long tmp = 1;
    for(long long i = 1; i<=a; i++)
        tmp*=i;

    return tmp;
}

long long factorial_rec(long long a) {
    if(a<2)
        return 1;
    else
       return a*factorial_rec(a-1);
    // always has a base case, sometimes more than 0
}

int main() {
    long long in;
    std::cout << "Enter(0 - 20): ";
    std::cin >> in;

    // iterative
    auto start1 = std::chrono::system_clock::now();
    
    std::cout << "factorial(" << in << ")[iterative]: " << factorial_it(in) << std::endl; // task 1
    
    auto end1 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    std::cout << "time:" << elapsed1.count()*1000000 << "us" << std::endl;

    // recursive
    auto start2 = std::chrono::system_clock::now();
    
    std::cout << "factorial(" << in << ")[recurisive]: " << factorial_rec(in) << std::endl; // task 2
    
    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << "time:" << elapsed2.count()*1000000 << "us" << std::endl;
}
