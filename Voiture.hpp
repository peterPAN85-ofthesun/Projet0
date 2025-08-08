#ifndef VOITURE_HPP
#define VOITURE_HPP

#include "Vehicule.hpp"

class Voiture : public Vehicule {
public:
  Voiture();
  Voiture(int const prix, int const portes);
  ~Voiture();
  void affiche() const;

private:
  int m_portes;
};

#endif
