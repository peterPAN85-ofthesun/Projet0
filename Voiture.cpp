#include "Voiture.hpp"

using namespace std;

Voiture::Voiture() : Vehicule(), m_portes(4) {}

void Voiture::affiche() const { cout << "Ceci est une voiture" << endl; }
