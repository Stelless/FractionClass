#pragma once
#include <iostream>

class Fraction
{
   int numerator{  };
   int denominator{  };
public:
   Fraction(); //Default
   Fraction(int num); //Integer
   Fraction(int num, int denom); //Rational

   Fraction operator !();
   Fraction operator +(Fraction add1); //Needs the (!)Operator
   friend std::ostream& operator<<(std::ostream& os, Fraction fraction);


};

