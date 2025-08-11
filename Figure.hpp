#ifndef FIGURE_HPP
#define FIGURE_HPP

class Figure {
public:
  virtual void affiche() const;
  virtual int perimetre() const = 0;
  virtual int aire() const = 0;

protected:
private:
};

class Triangle : public Figure {};

#endif
