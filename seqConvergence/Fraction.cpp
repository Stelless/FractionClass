#include "Fraction.h"
#include <iostream>

unsigned long long pos_remainder(unsigned long long divedend, unsigned long long divisor) {
	for (long quantity{ 0 }; divedend >= divisor; ++quantity) {
		divedend = divedend-divisor; // subtracting the divisor
	}
	return divedend; // Remainder willl only every be positive
}

unsigned long long GCF(unsigned long long num1, unsigned long long num2) {
	if (num1 < num2) std::swap(num1, num2); // Make sure num1 is the bigger one
	unsigned long long r = pos_remainder(num1, num2); // find the positive remainder after division
	if (r == 0) { return num2; } // this means the smaller one will always be the factor of the bigger one
	GCF(num2, r);
}

unsigned long long LCM(unsigned long long num1, unsigned long long num2) {
	return (num1 * num2) / GCF(num1, num2);
}

Fraction::Fraction() : numerator{ 0 }, denominator{ 1 } {

}
Fraction::Fraction(unsigned long long num) : numerator{ num }, denominator{ 1 } {

}
Fraction::Fraction(unsigned long long num, unsigned long long denom) : numerator{ num }, denominator{ denom } {

}

int Fraction::asInt() {
	return static_cast<int>(numerator / denominator);
}

unsigned long long Fraction::asDecimal() {
	return (numerator/denominator);
}

Fraction Fraction::operator!() {
	// "Reducing" operator
	//Check if the numerator and the denominator have a common factor
	// (other than one), divide both by it and return it
	unsigned long long fraction_GCF = GCF(numerator, denominator);
	if (fraction_GCF != 1) {
		return Fraction(numerator / fraction_GCF, denominator / fraction_GCF);
	}
	else
		return *this;
}


Fraction Fraction::operator +(Fraction add1) {
	if (denominator != add1.denominator) {
		unsigned long long common_divisor = LCM(denominator, add1.denominator);
		return Fraction((common_divisor/denominator) * numerator, common_divisor) + Fraction((common_divisor/add1.denominator) * add1.numerator, common_divisor);
	}
	return !Fraction(numerator+add1.numerator,denominator);
}

Fraction Fraction::operator *(Fraction mult1) {
	return !Fraction(numerator * mult1.numerator, denominator * mult1.denominator);
}

Fraction Fraction::operator /(Fraction div1) {
	return !(*this * Fraction(div1.denominator, div1.numerator));
}

Fraction Fraction::operator +=(Fraction add1) {
	return (*this + add1);
}

std::ostream& operator<<(std::ostream& os, Fraction fraction) {
	os << "[" << fraction.numerator << "/" << fraction.denominator << "]";
	return os;
}
