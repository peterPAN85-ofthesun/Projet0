//
//  perso.cpp
//  Projet0
//
//  Created by <author> on 01/08/2025.
//
//

#include "perso.hpp"

using namespace std;

Personnage::Personnage()
{
    m_vie = 100;
    m_mana = 100;
	m_arme = new Arme;
}

Personnage::Personnage(Personnage const &autre)
{
    m_vie = autre.m_vie;
    m_mana = autre.m_mana;
	m_arme = autre.m_arme;
}

Personnage::~Personnage()
{
	delete m_arme;
}

void Personnage::getDegats(int degats)
{
    m_vie -= degats;
}

void Personnage::attack(Personnage &cible)
{
	cible.getDegats(m_arme->getDegats());
}

void Personnage::getPV(int pv)
{
    m_vie += pv;
    if (m_vie > 100)
        m_vie = 100;
}

void Personnage::changeArme(Arme *arme)
{
	m_arme = arme;
}

bool Personnage::isAlive() const
{
    return m_vie > 0;
}

void Personnage::afficherEtat()
{
	cout << "Vie : " << m_vie << endl;
	cout << "Mana : " << m_mana << endl;
	m_arme->afficher();
}

int main()
{
    return 0;
}
