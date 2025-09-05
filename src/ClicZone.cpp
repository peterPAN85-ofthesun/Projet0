#include "ClicZone.hpp"

ClicZone::ClicZone() : m_zone((Rectangle){0, 0, 10, 10}), m_priority(0) {}
ClicZone::ClicZone(Rectangle const zone, unsigned const int priority)
    : m_zone(zone), m_priority(priority) {}
ClicZone::~ClicZone() {}

Rectangle ClicZone::getZone() const { return m_zone; }
void ClicZone::setZone(Rectangle const zone) { m_zone = zone; }
unsigned int ClicZone::getPriority() const { return m_priority; }
void ClicZone::setPriority(unsigned const int priority) {
  m_priority = priority;
}
std::string ClicZone::getMouseIcon() const { return m_mouseIcon; }
bool ClicZone::isInZone(Vector2 touchPosition) const {
  return touchPosition.x > m_zone.x && touchPosition.x < m_zone.width &&
         touchPosition.y > m_zone.y && touchPosition.y < m_zone.height;
}

bool operator<(ClicZone const &a, ClicZone const &b) {
  return a.getPriority() < b.getPriority();
}
bool operator>(ClicZone const &a, ClicZone const &b) {
  return a.getPriority() > b.getPriority();
}

IdleZone ::IdleZone() : ClicZone() {};
IdleZone ::IdleZone(Rectangle const zone, unsigned int const priority)
    : ClicZone(zone, priority) {
  m_mouseIcon = "src/resources/Cursor/idle.png";
};

RightZone ::RightZone() : ClicZone() {}
RightZone ::RightZone(Rectangle const zone, unsigned int const priority)
    : ClicZone(zone, priority) {
  m_mouseIcon = "src/resources/Cursor/droite.png";
}

LeftZone ::LeftZone() : ClicZone() {}
LeftZone ::LeftZone(Rectangle const zone, unsigned int const priority)
    : ClicZone(zone, priority) {
  m_mouseIcon = "src/resources/Cursor/gauche.png";
}
