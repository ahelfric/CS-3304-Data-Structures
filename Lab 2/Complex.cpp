#include <iostream>
#include <math.h>
#include "Complex.h"

using namespace std;

complex::complex(double real_in, double imaginary_in)
{
	real = real_in;
	imaginary = imaginary_in;
}

double complex::getReal() const
{
	return real;
}

double complex::getImaginary() const
{
	return imaginary;
}

void complex::setReal(double real_in)
{
	real = real_in;
}

void complex::setImaginary(double imaginary_in)
{
	imaginary = imaginary_in;
}

complex operator +(const complex& c1, const complex& c2) 
{
	return complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

complex operator -(const complex& c1, const complex& c2)
{
	return complex(c1.getReal() - c2.getReal(), c1.getImaginary() - c2.getImaginary());
}

complex operator /(const complex& c1, const complex& c2)
{
	//multiply by the conjugate
	complex cong_c2 = conjugate(c2);
	return c1 * cong_c2;
}

complex operator *(const complex& c1, const complex& c2)
{
	double real_out = ((c1.getReal() * c2.getReal())
					   - (c1.getImaginary() * c2.getImaginary()));
	double imaginary_out = ((c1.getReal() * c2.getImaginary()) 
							 + (c2.getReal() * c1.getImaginary()));
	return complex(real_out, imaginary_out);
}

complex conjugate(const complex& c1)
{
	return complex(c1.getReal(), -1 * c1.getImaginary());
}

ostream& operator <<(ostream & outs, const complex& c1)
{
	return outs << c1.getReal() << " " << c1.getImaginary() << "i";
}