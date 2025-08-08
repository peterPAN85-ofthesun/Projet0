#ifndef PERSO_HPP
#define PERSO_HPP

#include <iostream>
#include <string>

class Personnage {
public:
  Personnage();
  void recevoirDegat(int degats);
  void coupDePoing(Personnage &cible) const;

private:
  int m_vie;
  std::string m_nom;
};

#endif
