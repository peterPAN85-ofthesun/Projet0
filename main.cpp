#include "Moto.hpp"
#include "Vehicule.hpp"
#include "Voiture.hpp"

using namespace std;

int main() {
  Vehicule v;
  Voiture voi;
  Moto m;

  v.affiche();
  voi.affiche();
  m.affiche();

  return 0;
}
