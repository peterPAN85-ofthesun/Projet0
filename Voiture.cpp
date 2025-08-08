#include "Voiture.hpp"

using namespace std;

Voiture::Voiture() : Vehicule(), m_portes(4) {}
Voiture::Voiture(int const prix, int const portes)
    : Vehicule(prix), m_portes(portes) {}

Voiture::~Voiture() {}

void Voiture::affiche() const {
  cout << "Ceci est une voiture avec " << m_portes << " portes et qui coute "
       << m_prix << "euros." << endl;
}
