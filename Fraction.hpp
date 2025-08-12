#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <ostream>

class Fraction {
public:
  Fraction(int num, int den);
  Fraction(int num);
  Fraction();

  Fraction &operator*=(Fraction const &autre);

  bool estEgal(Fraction const &autre) const;
  void affiche(std::ostream &flux) const;

private:
  int m_numerateur;
  int m_denominateur;
};

std::ostream &operator<<(std::ostream &flux, Fraction const &fraction);
Fraction operator*(Fraction const &a, Fraction const &b);
bool operator==(Fraction const &a, Fraction const &b);
#endif
