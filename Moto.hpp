#ifndef MOTO_HPP
#define MOTO_HPP

#include "Vehicule.hpp"

class Moto : public Vehicule {
public:
  Moto();
  Moto(int const prix, double const vitesse);
  ~Moto();
  void affiche() const;

private:
  double m_vitesse;
};

#endif
