#include "Figure.hpp"
#include <cmath>

using namespace std;

////////////////// Figure //////////////////////

Figure::Figure() {}
Figure::~Figure() {}

void Figure::affiche() const {}

////////////////// Triangle /////////////////////

Triangle::Triangle() : m_base(1), m_hauteur(1) {}
Triangle::Triangle(int base, int hauteur) : m_base(base), m_hauteur(hauteur) {}
Triangle::~Triangle() {}

void Triangle::affiche() const { cout << "Ceci est un Triangle." << endl; }

double Triangle::perimetre() const {
  return (m_base + m_hauteur + sqrt(m_base * m_base + m_hauteur * m_hauteur));
}

double Triangle::aire() const { return (m_base * m_hauteur / 2); }

////////////////// Carre /////////////////////

Carre::Carre() : m_longueur(1) {}
Carre::Carre(double longueur) : m_longueur(longueur) {}
Carre::~Carre() {}

void Carre::affiche() const { cout << "Ceci est un Carre." << endl; }

double Carre::perimetre() const { return (4 * m_longueur); }

double Carre::aire() const { return (m_longueur * m_longueur); }

////////////////// Rectangle /////////////////////

Rectangle::Rectangle() : m_longueur(1), m_largeur(1) {}
Rectangle::Rectangle(double longueur, double largeur)
    : m_longueur(longueur), m_largeur(largeur) {}
Rectangle::~Rectangle() {}

void Rectangle::affiche() const { cout << "Ceci est un Rectangle" << endl; }

double Rectangle::perimetre() const { return (m_longueur * 2 + m_largeur * 2); }

double Rectangle::aire() const { return (m_longueur * m_largeur); }

////////////////// Cercle /////////////////////

Cercle::Cercle() : m_rayon(1) {}
Cercle::Cercle(double rayon) : m_rayon(rayon) {}
Cercle::~Cercle() {}

void Cercle::affiche() const { cout << "Ceci est un Cercle." << endl; }

double Cercle::perimetre() const { return (2 * M_PI * m_rayon); }

double Cercle::aire() const { return (4 * M_PI * m_rayon * m_rayon); }
