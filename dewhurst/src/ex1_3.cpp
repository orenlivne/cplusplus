//============================================================================
// Exercise 1.3: pointer reference types
//============================================================================

#include <iostream>
using namespace std;

int main_ex1_3() {
	int a = 42;
	int *b = &a;
	int *&c = b;
	//int &*d = b; // Error: cannot declare pointer to int&
	cout << "a " << a << " b " << b << " c " << c << endl;
	return 0;
}
