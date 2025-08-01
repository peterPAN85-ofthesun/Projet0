//
//  perso.hpp
//  Projet0
//
//  Created by <author> on 01/08/2025.
//
//

#ifndef perso_hpp
#define perso_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "arme.hpp"

class Personnage
{
public:
    Personnage();
    Personnage(Personnage const &autre);
    ~Personnage();
    void getDegats(int degats);
    void attack(Personnage &cible);
    void getPV(int pv);
	void changeArme(Arme &arme);
    bool isAlive() const;
	void afficherEtat();

private:
    int m_vie;
    int m_mana;
	Arme m_arme;
};


#endif /* perso_hpp */
