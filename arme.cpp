//
//  arme.cpp
//  Projet0
//
//  Created by <author> on 01/08/2025.
//
//

using namespace std;

#include "arme.hpp"

Arme::Arme()  {}

Arme::Arme(std::string nom, int degats)
{
	m_nom = nom;
	m_degats = degats;
}

Arme::~Arme()
{

}

void Arme::changer(string nom, int degats)
{
	m_nom = nom;
	m_degats = degats;
}

void Arme::afficher() const
{
	cout << "Arme : " << m_nom << endl;
	cout << "Degats : " << m_degats << endl;
}

string Arme::getNom() const
{
	return (m_nom);
}

int Arme::getDegats() const
{
	return (m_degats);
}
/*
int main()
{
	Arme hache;
	Arme epee("Epee", 10);
	Arme *foureau = new Arme("masse", 15);
	string nom = epee.getNom();
	int degat = epee.getDegats();
	hache.changer(nom, degat);
	foureau->afficher();
	delete foureau;

	return 0;
}
*/
