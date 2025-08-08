#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <iostream>

class Vehicule {
public:
  Vehicule();
  Vehicule(int const prix);
  virtual ~Vehicule();
  virtual void affiche() const;

protected:
  int m_prix;
};

#endif // !VEHICULE_HPP
#define VEHICULE_HPP
