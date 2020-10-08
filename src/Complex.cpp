#include "Complex.h"

Complex::Complex(float Input1, float Input2, int form)
	: Real(Input1), Imaginary(Input2), Magnitude(Input1), Argument(Input2)
{
	if (form == CARTESIAN) SetPolarForm();
	else if (form == POLAR) SetCartesianForm();
	else std::cout << "Warning: Invalid Complex Form!" << std::endl;
}

float Complex::GetReal() const { return Real; }
float Complex::GetImaginary() const { return Imaginary; }
float Complex::GetMagnitude() const { return Magnitude; }
float Complex::GetArgument() const { return Argument; }

// if complex parameters change, recalculate complementary complex form
void Complex::SetReal(float input) { Real = input;  SetPolarForm(); }
void Complex::SetImaginary(float input) { Imaginary = input;  SetPolarForm(); }
void Complex::SetMagnitude(float input) { Magnitude = input;  SetCartesianForm(); }
void Complex::SetArgument(float input) { Argument = input;  SetCartesianForm(); }

void Complex::SetCartesianForm()
{
	CalculateReal();
	CalculateImaginary();
}

void Complex::SetPolarForm()
{
	CalculateMagnitude();
	CalculateArgument();
}

void Complex::CalculateReal()
{
	Real = Magnitude * cos(Argument);
}

void Complex::CalculateImaginary()
{
	Imaginary = Magnitude * sin(Argument);
}

void Complex::CalculateMagnitude()
{
	Magnitude = sqrt(pow(Real, 2) + pow(Imaginary, 2));
}

void Complex::CalculateArgument()
{
	// answer presented between -PI and +PI
	// check for 1st quadrant and 4th quadrant
	if (Real > 0 && Imaginary >= 0 || Real > 0 && Imaginary <= 0)
	{
		Argument = atan(Imaginary / Real);
	}
	// check for 2nd quadrant
	else if (Real < 0 && Imaginary >= 0)
	{
		Argument = PI + atan(Imaginary / Real);
	}
	// check for 3rd quadrant
	else if (Real < 0 && Imaginary <= 0)
	{
		Argument = -PI + atan(Imaginary / Real);
	}
	// check for divide by 0 instances on positive Imaginary line
	else if (Real == 0 && Imaginary > 0)
	{
		Argument = PI / 2;
	}
	// check for divide by 0 instances on negative Imaginary line
	else if (Real == 0 && Imaginary < 0)
	{
		Argument = -PI / 2;
	}
	// else it's probably 0/0 indeterminate
	else
	{
		Argument = 0;
	}
}

void Complex::PrintCartesianForm() const
{
	std::cout << Real << std::showpos << Imaginary << std::noshowpos << "i " << std::endl;
}

void Complex::PrintPolarForm(int angleType) const
{
	float arg = 0.0;
	std::string str = "";
	if (angleType == DEGREES)
	{
		arg = Degrees(Argument);
		str = "degrees";
	}
	else
	{
		arg = Argument;
		str = "radians";
	}

	std::cout << Magnitude << ", " << arg << " " << str << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Complex& rhs)
{
	os << rhs.GetReal() << std::showpos << rhs.GetImaginary() << std::noshowpos << "i";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& rhs)
{
	// assuming cartesian form as input from stream
	float tempReal = 0.0;
	float tempImaginary = 0.0;

	std::string s;
	std::getline(is, s);
	std::stringstream ss(s);

	ss >> tempReal;
	ss >> tempImaginary;
	rhs.SetReal(tempReal);
	rhs.SetImaginary(tempImaginary);

	return is;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs.GetReal() + rhs.GetReal(), lhs.GetImaginary() + rhs.GetImaginary());
	return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs.GetReal() - rhs.GetReal(), lhs.GetImaginary() - rhs.GetImaginary());
	return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs.GetMagnitude() * rhs.GetMagnitude(), lhs.GetArgument() + rhs.GetArgument(), POLAR);
	return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs.GetMagnitude() / rhs.GetMagnitude(), lhs.GetArgument() - rhs.GetArgument(), POLAR);
	return result;
}

Complex logC(const Complex& X)
{
	// takes the natural lograithm of a complex number
	const float tempMag = X.GetMagnitude();
	const float tempArg = X.GetArgument();
	Complex result(log(tempMag), tempArg);
	return result;
}

// return result of complex number raised to the power of another complex number
Complex powC(const Complex& X, const Complex& Y)
{
	// takes complex number X to the power of complex number Y
	// X = a + bi
	const float a = X.GetReal();
	const float b = X.GetImaginary();

	// Y = c + di
	const float c = Y.GetReal();
	const float d = Y.GetImaginary();

	// X = mag(X)e^(i*arg(X))
	const float magX = X.GetMagnitude();
	const float argX = X.GetArgument();

	// calculate result in polar form
	const float Mag = pow(magX, c) / exp(d * argX);
	const float Arg = d * log(magX) + c * argX;
	Complex result(Mag, Arg, POLAR);
	return result;

}

Complex rootC(const Complex& X, const Complex& Y)
{
	// takes the complex root Y of complex number X
	Complex result;
	Complex root = Complex(1) / Y;
	result = powC(X, root);
	return result;
}

Complex BinetFibFormula(const Complex& n)
{
	// calculate the nth term of the fib sequence using a complex number as n
	return (powC(Complex(PHI), n) - (powC(Complex(-1 / PHI), n))) / sqrt(5.0f);
}

