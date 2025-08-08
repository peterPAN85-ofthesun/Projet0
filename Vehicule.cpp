#include "Vehicule.hpp"

using namespace std;

Vehicule::Vehicule() : m_prix(10000) {}
Vehicule::Vehicule(int const prix) : m_prix(prix) {}

Vehicule::~Vehicule() {}

void Vehicule::affiche() const {
  cout << "Ceci est un véhicule qui coute " << m_prix << endl;
}
