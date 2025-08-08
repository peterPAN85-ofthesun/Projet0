#include "Vehicule.hpp"

using namespace std;

Vehicule::Vehicule() : m_prix(10000) {}

void Vehicule::affiche() const { cout << "Ceci est un véhicule" << endl; }
