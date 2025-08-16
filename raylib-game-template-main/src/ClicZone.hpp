#ifndef CLICZONE_HPP
#define CLICZONE_HPP

#include "raylib.h"

class ClicZone {
public:
  ClicZone();
  ClicZone(Rectangle const zone, unsigned const int priority);
  ~ClicZone();

  Rectangle getZone() const;
  void setZone(Rectangle const zone);
  unsigned int getPriority() const;
  void setPriority(unsigned const int);

  bool isInZone(Vector2 touchPosition);

private:
  Rectangle m_zone;
  unsigned int m_priority;
};

bool operator<(ClicZone const &a, ClicZone const &b);
bool operator>(ClicZone const &a, ClicZone const &b);

#endif // !CLICZONE_HPP
