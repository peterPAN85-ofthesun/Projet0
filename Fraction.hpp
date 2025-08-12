#ifndef FRACTION_HPP
#define FRACTION_HPP

class Fraction {
public:
  Fraction(int num, int den);
  Fraction(int num);
  Fraction();

private:
  int m_numerateur;
  int m_denominateur;
};

#endif
