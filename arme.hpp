//
//  arme.hpp
//  Projet0
//
//  Created by <author> on 01/08/2025.
//
//

#ifndef arme_hpp
#define arme_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class Arme {
private:
    std::string	m_nom;
    int			m_degats;

public:
	Arme();
	Arme(std::string nom,int degats);
	void		changer(std::string nom, int degats);
	void		afficher() const;
	std::string	getNom() const;
	int			getDegats() const;


protected:

};


#endif /* arme_hpp */
