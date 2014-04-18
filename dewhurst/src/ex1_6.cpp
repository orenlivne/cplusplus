//============================================================================
// Exercise 1.6: What output does the following program produce on your
// system? Explain.
//============================================================================

#include <stdio.h>
using namespace std;

int& f() {
	int i = 1;
	return i;
}

int g() {
	int j = 2;
	return j;
}

int main_ex1_6() {
	int &ri = f();
	g();
	printf("%d\n", ri);
	return 0;
}
