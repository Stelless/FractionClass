#include "Fraction.h"
#include <iostream>

int pos_remainder(int divedend, int divisor) {
	for (int quantity{ 0 }; divedend >= divisor; ++quantity) {
		divedend += -divisor; // subtracting the divisor
	}
	return divedend; // Remainder willl only every be positive
}

int GCF(int num1, int num2) {
	if (num1 < num2) std::swap(num1, num2); // Make sure num1 is the bigger one
	int r = pos_remainder(num1, num2); // find the positive remainder after division
	if (r == 0) { return num2; } // this means the smaller one will always be the factor of the bigger one
	GCF(num2, r);
}

int LCM(int num1, int num2) {
	return std::abs(num1 * num2) / GCF(num1, num2);
}

Fraction::Fraction() : numerator{ 0 }, denominator{ 1 } {

}
Fraction::Fraction(int num) : numerator{ num }, denominator{ 1 } {

}
Fraction::Fraction(int num, int denom) : numerator{ num }, denominator{denom} {

}
Fraction Fraction::operator!() {
   // "Reducing" operator
   //Check if the numerator and the denominator have a common factor
   // (other than one), divide both by it and return it
	int fraction_GCF = GCF(numerator, denominator);
	if (fraction_GCF != 1) {
		return Fraction(numerator / fraction_GCF, denominator / fraction_GCF);
	}
	else
		return *this;
}


Fraction Fraction::operator +(Fraction add1) {
   // When we add fractions we need to find a common denominator(LCM)
   // and find the equivalent fractions. We then need to reduce the 
   // fraction with a new operator !
	return add1;
}

std::ostream& operator<<(std::ostream& os, Fraction fraction) {
	os << "[" << fraction.numerator << "/" << fraction.denominator << "]";
	return os;
}
