//============================================================================
// Exercise 1.1: Write a C++ program that tells you how many bits are used
// to represent objects of type char, short, int, and long.
//============================================================================

#include <iostream>
using namespace std;

const int b = 8; // Number of bits in a byte

template<typename T>
void print_size(const char* name, T value) {
	cout << name << ": " << b * sizeof(value) << endl;
}

int main() {
	print_size<char>("char", (char) 1);
	print_size<short>("short", (short) 1);
	print_size<int>("int", (int) 1);
	print_size<long>("long", (long) 1);
	print_size<long>("long long", (long long) 1);
}
