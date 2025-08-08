#include "Moto.hpp"
#include "Vehicule.hpp"
#include "Voiture.hpp"

using namespace std;

void presenter(Vehicule v) { v.affiche(); }

int main() {
  Vehicule v;
  Voiture voi;
  Moto m;

  presenter(v);
  presenter(voi);
  presenter(m);

  return 0;
}
