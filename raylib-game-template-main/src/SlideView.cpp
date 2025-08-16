#include "SlideView.hpp"
#include <iostream>
#include <raylib.h>

using namespace std;

SlideView::SlideView() {}

SlideView::SlideView(string imagePath) : m_imagePath(imagePath) {}

SlideView::~SlideView() {
  for (map<SLIDE_STRUCT>::iterator it = m_slideMap.begin();
       it != m_slideMap.end(); ++it) {
    //(it->first)->rmSlideMap(*this);
    cout << "salut";
  }
}

map<SLIDE_STRUCT> SlideView::getSlideMap() const { return m_slideMap; }

string SlideView::getSlideImagePath() const { return m_imagePath; }

vector<SlideView *> SlideView::getPriorityList() { return m_priorityList; }

void SlideView::print(ostream &flux) {
  flux << "Image path : " << m_imagePath << endl << endl;
  this->getPriorityList();
  for (long unsigned int i = 0; i < m_priorityList.size(); ++i) {
    flux << i << " : " << m_priorityList[i]->getSlideImagePath()
         << " ----[PRIORITY]-----> "
         << m_slideMap.find(m_priorityList[i])->second.getPriority() << endl;
  }
}

void SlideView::addSlideMap(pair<SLIDE_STRUCT> slide) {
  m_slideMap.insert(slide);
  m_priorityList.push_back(slide.first);
  this->sortPriorityList();
}

void SlideView::rmSlideMap(SlideView &slide) {
  vector<SlideView *>::iterator i = m_priorityList.begin();
  m_slideMap.erase(&slide);
  while (*i != &slide) {
    i++;
  }
  m_priorityList.erase(i);
  this->sortPriorityList();
}

void SlideView::link(std::pair<SLIDE_STRUCT> slide, ClicZone cliczone) {
  m_slideMap.insert(slide);
  slide.first->addSlideMap(pair<SLIDE_STRUCT>(this, cliczone));
}

void SlideView::unLink(SlideView *slide) {
  m_slideMap.erase(slide);
  slide->rmSlideMap(*this);
}
// bool SlideView::isInZone(Vector2 touchPosition) {}

void SlideView::sortPriorityList() {
  SlideView *tmp;

  m_priorityList.clear();
  for (map<SLIDE_STRUCT>::iterator it = m_slideMap.begin();
       it != m_slideMap.end(); ++it) {
    m_priorityList.push_back(it->first);
  }

  for (long unsigned int i = 0; i < m_priorityList.size(); ++i) {
    for (long unsigned int j = i + 1; j < m_priorityList.size(); ++j) {
      if (m_slideMap[m_priorityList[i]] > m_slideMap[m_priorityList[j]]) {
        tmp = m_priorityList[i];
        m_priorityList[i] = m_priorityList[j];
        m_priorityList[j] = tmp;
      }
    }
  }
}

bool operator<(pair<SLIDE_STRUCT> const &a, pair<SLIDE_STRUCT> const &b) {
  return a.second < b.second;
}
bool operator>(pair<SLIDE_STRUCT> const &a, pair<SLIDE_STRUCT> const &b) {
  return a.second > b.second;
}
ostream &operator<<(ostream &flux, SlideView &slide) {
  slide.print(flux);
  return flux;
}

int main() {
  SlideView *slide1 = new SlideView(
      "/home/gregoire/Documents/Script/C++/Projet0/raylib-game-template-main/"
      "src/resources/RayLibTest/01_000.png");
  SlideView *slide2 = new SlideView(
      "/home/gregoire/Documents/Script/C++/Projet0/raylib-game-template-main/"
      "src/resources/RayLibTest/01_090.png");
  SlideView *slide3 = new SlideView(
      "/home/gregoire/Documents/Script/C++/Projet0/raylib-game-template-main/"
      "src/resources/RayLibTest/01_270.png");
  SlideView *slide4 = new SlideView(
      "/home/gregoire/Documents/Script/C++/Projet0/raylib-game-template-main/"
      "src/resources/RayLibTest/02_000.png");
  Rectangle const zone{0, 0, 100, 00};
  ClicZone z1(zone, 2);
  ClicZone z2(zone, 1);
  ClicZone z3(zone, 10);
  slide1->addSlideMap(pair<SLIDE_STRUCT>(slide2, z1));
  slide1->addSlideMap(pair<SLIDE_STRUCT>(slide3, z2));
  slide1->addSlideMap(pair<SLIDE_STRUCT>(slide4, z3));
  delete slide2;
  cout << *slide1;
}
