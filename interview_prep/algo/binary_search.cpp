#include <iostream>
#include <bits/stdc++.h>


int binarySearch(int arr[], int l, int r, int x) {
	r--;
	while (l <= r) {
		int m = (l + r) / 2;

		// check if x is present at mid
		if (arr[m] == x)
			return m;

		// if x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// if x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was not present
	return -1;
}

// driver code
int main(void) {
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 50;
	
  int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	
  (result == -1) ? std::cout << "Element is not present in array\n" : std::cout << "Element is present at index: " << result << std::endl;

	return 0;
}
