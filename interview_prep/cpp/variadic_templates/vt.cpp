#include <iostream>

// base case
// this prints the last argument which is null
void print() {
	std::cout << std::endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
	// this prints the first argument
	std::cout << arg << "\t";

	// recursive call
	// this prints stuff from 1 to n
	print(args...);
}

int main() {
	print(1, 3.2f, 3.14, "a" "bb", "ccc");
}
