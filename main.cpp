#include "Moto.hpp"
#include "Vehicule.hpp"
#include "Voiture.hpp"

using namespace std;

void presenter(Vehicule const &v) { v.affiche(); }

int main() {
  Vehicule *v(0);
  v = new Voiture;

  v->affiche();

  delete v;

  return 0;
}
