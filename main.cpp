#include "perso.hpp"
using namespace std;

int main()
{
    Personnage david, goliath;
	Arme hache("Double hache", 40);

    goliath.attack(david);
    david.getPV(20);
    goliath.attack(david);
    david.attack(goliath);

	goliath.changeArme(&hache);
    goliath.attack(david);

	cout << "David" << endl;
	david.afficherEtat();
	cout << endl << "Goliath" << endl;
	goliath.afficherEtat();
    return(0);
}
