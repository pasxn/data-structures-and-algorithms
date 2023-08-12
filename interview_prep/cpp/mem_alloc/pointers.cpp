#include <iostream>


class Motor {
	public:
		int p1, p2, pwm;
		Motor(int p1, int p2, int pwm) : p1(p1), p2(p2), pwm(pwm) {}
};

int func(float x) {
	return (int)x + 1;
}

void modifyValue(int *ptr) {
  *ptr = 100;
}

void allocateMemory(int **ptr) {
  *ptr = new int;
}

int main() {
	using namespace std;

  int* np = nullptr;

	int i = 100;
	int* i_ptr = &i;

  Motor m (10,11,12);
	Motor* m_ptr = &m;

	int (*f_ptr)(float) = &func;

	cout << "i          : " << i             << endl;
	cout << "i_ptr      : " << i_ptr         << endl;
  cout << "i_ptr_drf  : " << *i_ptr        << endl;
  cout << endl;

  cout << "m_ptr      : " << m_ptr         << endl;
	cout << "m.p1       : " << m.p1          << endl;
	cout << "m_ptr->p1  : " << m_ptr->p1     << endl;
  cout << endl;

	cout << "f_ptr      : " << f_ptr         << endl;
  cout << "func       : " << func(3.0)     << endl;
	cout << "*f_ptr(3.0): " << (*f_ptr)(3.0) << endl;
  cout << endl;

	int** i_pp = &i_ptr;
	cout << "  i_pp: " <<   i_pp << endl;
	cout << " *i_pp: " <<  *i_pp << endl;
	cout << "**i_pp: " << **i_pp << endl;
  cout << endl;

  int arr[] = {1, 2, 3, 4};
  int *arrPtr = arr;
  
  cout << "pointer arithmetic -> " << endl;
  for(int i = 0; i < 4; i++) {
    cout << *(arrPtr + i) << " ";
  }
  cout << endl;
  cout << endl;

  cout << "dynamic memory allocation ->" << endl;
  int *dynamicPtr = new int[10];
  for(int i = 0; i < 10; i++) {
    *(dynamicPtr + i) = {10};
  }

  for(int i = 0; i < 10; i++) {
    cout << *(dynamicPtr + i) << " ";
  }
  cout << endl;

  delete dynamicPtr;
  cout << endl;

  cout << "dynamic memory allocation C ->" << endl;
  int *dynamicPtrC = (int*)malloc(sizeof(int)*10);
  for(int i = 0; i < 10; i++) {
    *(dynamicPtrC + i) = {10};
  }

  for(int i = 0; i < 10; i++) {
    cout << *(dynamicPtrC + i) << " ";
  }  

  free(dynamicPtrC);
  cout << endl;
  cout << endl;

  cout << "passing to a function as a pointer -> " << endl;
  int num = 5;
  cout << "number before modifying: " << num << endl;
  modifyValue(&num);
  cout << "number after modifying: " << num << endl;
  cout << endl;

  return 0;
}
