//============================================================================
// Exercise 1.4: Given the declarations, which of the following assignments
// are legal, illegal, and why?
//============================================================================

#include <iostream>
using namespace std;

int main_ex1_4() {
	char c;
	const char cc = 'a';
	char *pc;
	const char *pcc;
	char * const cpc = &c;
	const char * const cpcc = &cc;
	char * const *pcpc;

	c = cc;			// copies cc to c by value
	// cc = c;		// can't assign const
	pcc = &c;		// while *pcc is const, pcc can be assigned to a non-const
	pcc = &cc;		// consts match
	pc = &c;		// no consts involved => match
	// pc = &cc;	// otherwise the const cc could be modified via *pc
	// pc = pcc;	// *pcc may be modified via *pc - both non-const
	pc = cpc;		// both point to a mutable char
	// pc = cpcc;	// otherwise the const *cpcc could be modified via *pc
	// cpc = pc;	// const pointer cannot be assigned
	*cpc = *pc;		// the value *cpc is mutable even though cpc is a const pointer
	pc = *pcpc;		// *pcpc is a pointer to a mutable char; so is pc
	**pcpc = *pc;	// *pcpc is fixed, but **pcpc is a mutable char, like *pc
	*pc = **pcpc; 	// both are mutable chars

	return 0;
}
