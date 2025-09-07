#ifndef CLICZONE_HPP
#define CLICZONE_HPP

#include "raylib.h"
#include "string"

class ClicZone {
public:
  ClicZone();
  ClicZone(Rectangle const zone, unsigned const int priority);
  ~ClicZone();

  Rectangle getZone() const;
  void setZone(Rectangle const zone);
  unsigned int getPriority() const;
  void setPriority(unsigned const int);
  std::string getMouseIcon() const;
  bool isInZone(Vector2 touchPosition) const;

protected:
  Rectangle m_zone;
  unsigned int m_priority;
  std::string m_mouseIcon;
};

bool operator<(ClicZone const &a, ClicZone const &b);
bool operator>(ClicZone const &a, ClicZone const &b);

class IdleZone : public ClicZone {
public:
  IdleZone();
  IdleZone(Rectangle const zone, unsigned int const priority);
};

class ForwardZone : public ClicZone {
public:
  ForwardZone();
  ForwardZone(Rectangle const zone, unsigned int const priority);
};

class RightZone : public ClicZone {
public:
  RightZone();
  RightZone(Rectangle const zone, unsigned int const priority);
};

class LeftZone : public ClicZone {
public:
  LeftZone();
  LeftZone(Rectangle const zone, unsigned int const priority);
};

#endif // !CLICZONE_HPP
