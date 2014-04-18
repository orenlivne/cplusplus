//============================================================================
// Exercise 1.2: The output of this program is a 3 b 2 c 2. Explain.
//============================================================================

#include <iostream>
using namespace std;

int f(int i) {
	return ++i;
}

int g(int& i) {
	return ++i;
}

int h(char& i) {
	return ++i;
}

int main_ex1_2() {
	int a = 0, b = 0, c = 0;
	a += f(g(a));
	int u;
	u = f(b);
	int& temp = u;
	b += g(temp);
	c += f(h((char&) c));
	cout << "a " << a << " b " << b << " c " << endl;
	return 0;
}
