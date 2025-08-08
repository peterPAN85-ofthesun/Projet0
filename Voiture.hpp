#ifndef VOITURE_HPP
#define VOITURE_HPP

#include "Vehicule.hpp"

class Voiture : public Vehicule {
public:
  Voiture();
  virtual void affiche() const;

private:
  int m_portes;
};

#endif
