# Complex-Numbers
Complex number class and functions in C++

### This project contains 1 header and 2 source files:
**Complex.h** = Header file for declarations of complex number class and functions\
**Complex.cpp** = Source file containing the definitions of the "Complex.h" file\
**main.cpp** = Main program code which has some examples on how to use the class

### How to create a complex number object?
The Complex class constructor takes 2 inputs and a form. By default the form is set to Cartesian and the 2 inputs act as the real and imaginary part of the complex number.

**Complex number(-2, 3);**

This sets the variable **number** to -2 + 3i. To set a complex number in polar form, use the keyword **POLAR** as the 3rd argument. The 1st and 2nd argument now become magnitude and argument respectively. The argument is taken in as radians.

**Complex number(5, PI/3, POLAR);**

### How to do arithmatic with complex numbers?
The +, -, *, and / operator have been overidden for the Complex class type.

**Complex C1(2, 3);\
  Complex C2(3, 4);\
  Complex C3 = C1 + C2;\
  Complex C4 = C1 - C2;\
  Complex C5 = C1 * C2;\
  Complex C6 = C1 / C2;**

This also works with primative types as shown:

**Complex number = 1.312 + C2;**

A very readable way to display complex numbers in cartesian form is to set a complex variable i.

**Complex i(0, 1);\
  Complex number = -3 + 6*i;**
  
This is not recommended because it's implictly converting -3 and 6 to complex numbers which is inefficient.
  
## How to print complex numbers to the console?
One can print a Complex object to the console by simply using the std::cout << operation. This will print it out in cartesian form.

**std::cout << C1 << std::endl;**

An alternative is to use the built in method.

**C1.PrintCartesianForm();**

The Polar form can also be displayed and takes an argument **RADIANS** by default for radians. **DEGREES** can be used for degrees.

**C2.PrintPolarForm(DEGREES);**

Complex numbers can be read from the console using the **>>** operator to be placed into an Complex class type. Note that there should be no spaces in the input.

**Complex input;\
std::cin >> input;**

## Some fun additionals
A complex number can be taken to the power of another complex number.

**Complex result;\
  result = powC(C1, C2);** //C1 to the power of C2

The complex root of a complex number can be found.

**result = rootC(C1, C2);** //The complex root C1 of C2
	
The nth term in the fib sequence can be found even when n is a non-integer resulting in a complex result.

**result = BinetFibFormula(2.3);**

n can also be complex.

**result = BinetFibFormula(C1);**
