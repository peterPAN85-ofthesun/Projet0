#ifndef MOTO_HPP
#define MOTO_HPP

#include "Vehicule.hpp"

class Moto : public Vehicule {
public:
  Moto();
  virtual void affiche() const;

private:
  double m_vitesse;
};

#endif
