/* Contoh Program dalam Bahasa C++ */
// C++ program to illustrate the feholdexcept() function

/*	Source by GeeksForGeeks
	Modified for Learn by Rizky Khapidsyah
*/

#include <iostream>    /* printf, puts */
#include <cfenv>       /* feholdexcept, feclearexcept, fetestexcept, feupdateenv, FE_* */
#include <cmath>       /* log */
#include <conio.h>

#pragma fenv_access (on)

using namespace std;

// function to print raised exceptions
void raised_exceptions() {
	cout << "Exceptions raised are : ";

	if (fetestexcept(FE_DIVBYZERO)) {
		cout << " FE_DIVBYZERO\n";
	} else if (fetestexcept(FE_INVALID)) {
		cout << " FE_INVALID\n";
	} else if (fetestexcept(FE_OVERFLOW)) {
		cout << " FE_OVERFLOW\n";
	} else if (fetestexcept(FE_UNDERFLOW)) {
		cout << " FE_UNDERFLOW\n";
	} else {
		cout << " No exception found\n";
	}
		
	return;
}

// Driver code
int main() {
	// environment variable
	fenv_t envp;

	// raise certain exceptions
	feraiseexcept(FE_DIVBYZERO);
	// print the raised exception
	raised_exceptions();

	// saves and clears current
	// exceptions by feholexcept function
	feholdexcept(&envp);
	// no exception found
	raised_exceptions();

	// restores the previously
	// saved exceptions
	feupdateenv(&envp);
	raised_exceptions();

	_getch();
	return 0;
}
