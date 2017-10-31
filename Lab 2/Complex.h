#include <iostream>

class complex
{
	public:
		// CONSTRUCTOR
		complex(double real_in, double imaginary_in);
		// CONSTANT MEMBER FUNCTIONS
		double getReal() const;
		double getImaginary() const;
		// SET METHODS
		void setReal(double real_in);
		void setImaginary(double imaginary_in);
	private:
		double real, imaginary; //double values for parts of complex number
};

//	NONMEMBER FUNCTIONS for the complex class
complex operator +(const complex& c1, const complex& c2);
complex operator -(const complex& c1, const complex& c2);
complex operator /(const complex& c1, const complex& c2);
complex operator *(const complex& c1, const complex& c2);
complex conjugate(const complex& c1);
std::ostream& operator <<(std::ostream & outs, const complex& c1);

//Include
// Complex number:
//  Real part
//  Imaginary part
// Operations
//  Constructor: Real x Real -> Complex
//  Addition: Complex x Complex -> Complex
//  Subtraction: Complex x Complex -> Complex
//  Multiplication: Complex x Complex -> Complex
//  Division: Complex x Complex -> Complex
//   *divisor cannot be 0*
//  Conjugate: Complex -> Conjugate
//  Output: 
//  