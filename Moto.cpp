#include "Moto.hpp"

using namespace std;

Moto::Moto() : Vehicule(), m_vitesse(300) {}

void Moto::affiche() const { cout << "Ceci est une moto" << endl; }
