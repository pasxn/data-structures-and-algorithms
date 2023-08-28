/*
 * lambda expressions can be used inline or passed as an argument.
 * aka annonymous functors
 * 
 * ex -> auto greet = [](){ //greet here };
 * ex -> auto greet = [lambda introducer](parameter list){ //greet here };
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>


int main() {

  // create a lambda function that prints "Hello World!"
  auto greet = []() { std::cout << "Hello World!" << std::endl; };

  // call lambda function
  greet();


  // return type can be explicitly specified or deduced from the return statement
  // explicitly specifying is commonly done when multiple statements returns different types.
  // no matter what type of value is returned by the various return statements, they are all explicitly converted to int type.
  auto add = [] (float a, float b) -> int{ return a + b; };

  std::cout << add(4.0f, 2.0f) << std::endl;


  // by default, lambda functions cannot access variables of the enclosing function.
  // in order to access those variables, we use the capture clause.
  // capture by value and capture by reference!
  // we can only read the variable inside the lambda body but cannot modify it.
  
  int num_main = 100;

  auto my_lambda = [num_main] () { std::cout << "num_main: " << num_main <<std::endl; };
  my_lambda();

  auto my_lambda_ref = [&num_main] () { num_main = 900; };
  my_lambda_ref();
  std::cout << num_main << std::endl;

  // implicit capture by value, here, [=] says all the variables of the enclosing function are captured by value.
  auto my_lambda_impl_val = [=] (){ /* lambda body */ };

  // implicit capture by reference, here, [&] says all the variables of the enclosing function are captured by reference.
  auto my_lambda_impl_ref = [&] (){ /* lambda body */ };


  // passing to STL functions
  // initialize vector of integers
  std::vector<int> nums = {1, 2, 3, 4, 5, 8, 10, 12};

  int even_count = std::count_if(nums.begin(), nums.end(), [](int num) {
    return num % 2 == 0;
  });

  std::cout << "There are " << even_count << " even numbers.\n";


  return 0;
}
