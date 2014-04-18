//============================================================================
// Exercise 1.5: Explain the semantics of the following functions.
//============================================================================

#include <iostream>
using namespace std;

void swap1(int *a, int *b) {
	// Swap a, b via pointers
	int t = *a;
	*a = *b;
	*b = t;
}

void swap2(int &a, int &b) {
	// Swap a, b via references, cleaner syntax
	int t = a;
	a = b;
	b = t;
}

void flop(int a, int b) {
	// a,b are unchanged outside this function
	int t;
	t = a;
	a = b;
	b = t;
}

int main_ex1_5() {
	int a = 1, b = 2;
	cout << "a " << a << " b " << b << endl; // a 1 b 2
	swap1(&a, &b);
	cout << "a " << a << " b " << b << endl; // a 2 b 1
	swap2(a, b);
	cout << "a " << a << " b " << b << endl; // a 1 b 2
	flop(a, b);
	cout << "a " << a << " b " << b << endl; // a 1 b 2
	return 0;
}
