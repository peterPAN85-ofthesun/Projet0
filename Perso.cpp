#include "Perso.hpp"

Personnage::Personnage() {
  m_vie = 100;
  m_nom = "Claude";
}

void Personnage::recevoirDegat(int degats) { m_vie -= degats; }

void Personnage::coupDePoing(Personnage &cible) const {
  cible.recevoirDegat(10);
}
