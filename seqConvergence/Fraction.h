#pragma once
#include <iostream>

class Fraction
{
   unsigned long long numerator{  };
   unsigned long long denominator{  };
public:
   Fraction(); //Default
   Fraction(unsigned long long num); //Integer
   Fraction(unsigned long long num, unsigned long long denom); //Rational

   int asInt();
   unsigned long long asDecimal();

   Fraction operator !();
   Fraction operator +(Fraction add1);
   Fraction operator *(Fraction mult1);
   Fraction operator /(Fraction div1);

   Fraction operator +=(Fraction add1);
   friend std::ostream& operator<<(std::ostream& os, Fraction fraction);


};

