#include "Moto.hpp"

using namespace std;

Moto::Moto() : Vehicule(), m_vitesse(300) {}
Moto::Moto(int const prix, double const vitesse)
    : Vehicule(prix), m_vitesse(vitesse) {}

Moto::~Moto() {}
void Moto::affiche() const {
  cout << "Ceci est une moto qui roule jusqu'a " << m_vitesse
       << " k/h et qui coute " << m_prix << "euros." << endl;
}
