#include "Voiture.hpp"

using namespace std;

Voiture::Voiture() : Vehicule(), m_portes(4) {}

Voiture::~Voiture() {}

void Voiture::affiche() const { cout << "Ceci est une voiture" << endl; }
