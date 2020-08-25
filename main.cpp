/* Complex number code examples */
#include <iostream>
#include "Complex.h"

int main() {

	/* Defining complex numbers in cartesian form */
	// Complex number(Real, Imaginary)
	Complex C1(2, 3);
	Complex C2(3, 4);
	Complex C3 = C1 + C2;
	C3.PrintCartesianForm();

	/* A clear way of displaying complex numbers in cartesian form */
	Complex i(0, 1);
	Complex number = -3 + 6*i; // inefficient because of type converting
	std::cout << "Complex number = " << number << std::endl;

	/* Defining complex numbers in polar form */
	// Complex number(Magnitude, Argument in radians)
	Complex C4(1, PI / 3, POLAR);
	Complex C5(2, PI / 4, POLAR);
	Complex C6 = C4 + C5;
	C5.PrintPolarForm(DEGREES);

	/* Taking natural log of complex numbers */
	Complex C7(5, -3);
	logC(C7).PrintCartesianForm();

	/* Taking complex number X to power of complex number Y */
	// powC(X, Y)
	Complex C8(-4, 6);
	Complex C9(1, -2);
	powC(C8, C9).PrintPolarForm(DEGREES);

	/* Taking complex root Y of a complex number X */
	// rootC(X, Y)
	Complex C10(54, 33.231);
	Complex C11(0.231, 1644);
	rootC(C10, C11).PrintCartesianForm();

	/* Getting the nth term in the fib sequence */
	// When n is a non-integer, the result is complex
	Complex Cfib = BinetFibFormula(2.3);
	Cfib.PrintCartesianForm();
	// n can also be complex
	Complex C12(3, 5);
	Cfib = BinetFibFormula(C12);
	Cfib.PrintCartesianForm();

	/* Get complex number as input */
	// e.g. 3+2i (no spaces)
	Complex input;
	std::cin >> input;
	input.PrintCartesianForm();

	return 0;
}

