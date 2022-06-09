#include <iostream>
#include "Fraction.h"

using namespace std;


int main() {
	/*
	Program that shows that SERIES 1/n does not converge to any number
	- I will show thus by asking for ANY number (no matter how big) and I will be able to produce it (theoretically) with the series 1/n
	*/
	cout << "hello! " << endl;



	Fraction frac1{ 6, 8 };
	Fraction frac2{ 33, 64 };

	cout << frac1 << " + " << frac2 << " = " << (frac1 + frac2) << endl;
	cout << !frac1 << " + " << !frac2 << " = " << !frac1 + !frac2 << endl;
	
	cout << Fraction(3, 8) << " * " <<  Fraction(2) << " = " << Fraction(3, 8) * Fraction(2) << endl;

	cout << Fraction(4,2) << " / " << Fraction(1,7) << " = " << Fraction(4, 2) / Fraction(1, 7) << endl;
	cout << endl;
	int epsilon{ 3 };
	Fraction sum{};
	size_t n{ 1 };
	for (; sum.asDecimal() < epsilon; ++n) {
		cout << sum << " + " << Fraction(1, n);
		sum = sum + Fraction(1, n);
		cout << " " << sum << " or " << sum.asDecimal() << endl;
	}
	cout << endl;
	cout << "Sum: " << sum.asDecimal() << " or " << sum << endl;
	cout << "n: " << n << " terms needed." << endl;
}