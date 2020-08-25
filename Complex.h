#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "math.h"
#define Degrees(x) (360.0f * x) / (2.0f * PI)
constexpr auto CARTESIAN = 0;
constexpr auto POLAR = 1;
constexpr auto DEGREES = 0;
constexpr auto RADIANS = 1;
constexpr auto PI = 3.14159265f;
constexpr auto PHI = 1.6180339f;

/* A class for complex numbers */
class Complex
{
private:
	/* Cartesian form */
	float Real;
	float Imaginary;

	/* Polar form */
	float Magnitude;
	float Argument;

public:
	Complex(float Input1 = 0.0, float Input2 = 0.0, int form = CARTESIAN);

	float GetReal() const;
	float GetImaginary() const;
	float GetMagnitude() const;
	float GetArgument() const;

	void SetReal(float input);
	void SetImaginary(float input);
	void SetMagnitude(float input);
	void SetArgument(float input);

	void SetCartesianForm();
	void SetPolarForm();

	void CalculateReal();
	void CalculateImaginary();
	void CalculateMagnitude();
	void CalculateArgument();

	void PrintCartesianForm() const;
	void PrintPolarForm(int angleType = RADIANS) const;

};

std::ostream& operator<<(std::ostream& os, const Complex& rhs);
std::istream& operator>>(std::istream& os, Complex& rhs);

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

Complex logC(const Complex& X);
Complex powC(const Complex& X, const Complex& Y);
Complex rootC(const Complex& X, const Complex& Y);
Complex BinetFibFormula(const Complex& n);

template<typename Container>
void fib(int a, int b, int n, Container& fibSeq)
{
	if (n > 0)
	{
		fibSeq.push_back(a);
		fib(b, a + b, --n, fibSeq);
	}
}
