#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <cmath>
#include <iostream>
#include <math.h>

class Figure {
public:
  Figure();
  virtual ~Figure();

  virtual void affiche() const;
  virtual double perimetre() const = 0;
  virtual double aire() const = 0;

protected:
private:
};

class Triangle : public Figure {
public:
  Triangle();
  Triangle(int base, int hauteur);
  virtual ~Triangle();

  void affiche() const;
  double perimetre() const;
  double aire() const;

protected:
  double m_base;
  double m_hauteur;
};

class Carre : public Figure {
public:
  Carre();
  Carre(double longueur);
  virtual ~Carre();

  void affiche() const;
  double perimetre() const;
  double aire() const;

protected:
  double m_longueur;
};

class Rectangle : public Figure {
public:
  Rectangle();
  Rectangle(double longueur, double largeur);
  virtual ~Rectangle();

  void affiche() const;
  double perimetre() const;
  double aire() const;

protected:
  double m_longueur;
  double m_largeur;
};

class Cercle : public Figure {
public:
  Cercle();
  Cercle(double rayon);
  virtual ~Cercle();

  void affiche() const;
  double perimetre() const;
  double aire() const;

protected:
  double m_rayon;
};

#endif
