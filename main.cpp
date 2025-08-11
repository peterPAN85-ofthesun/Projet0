#include "Figure.hpp"
#include <vector>

using namespace std;

int main() {
  vector<Figure *> figures;
  figures.push_back(new Triangle());
  figures.push_back(new Carre());
  figures.push_back(new Rectangle());
  figures.push_back(new Cercle());

  for (long unsigned int i = 0; i < figures.size(); i++) {
    figures[i]->affiche();
    cout << "Perimetre : " << figures[i]->perimetre() << endl;
    cout << "Aire : " << figures[i]->aire() << endl;
    delete figures[i];
    figures[i] = 0;
  }

  return 0;
}
