#ifndef SLIDEVIEW_HPP
#define SLIDEVIEW_HPP

#define SLIDE_STRUCT SlideView *, ClicZone

#include "ClicZone.hpp"
#include "raylib.h"
#include <map>
#include <string>
#include <utility>
#include <vector>

class SlideView {
public:
  SlideView();
  SlideView(std::string imagePath);
  ~SlideView();

  std::map<SLIDE_STRUCT> getSlideMap() const;

  void addSlideMap(std::pair<SLIDE_STRUCT> slideTarget);
  void rmSlideMap(SlideView &slide);
  void sortMapPriority();

  SlideView *getTheSlideViewTargerted(Vector2 touchPosition);

protected:
private:
  std::string m_imagePath;
  std::map<SLIDE_STRUCT> m_slideMap;
  std::vector<SlideView *> m_priorityList;
};

bool operator<(std::pair<SLIDE_STRUCT> const &a,
               std::pair<SLIDE_STRUCT> const &b);
bool operator>(std::pair<SLIDE_STRUCT> const &a,
               std::pair<SLIDE_STRUCT> const &b);
#endif //! SLIDEVIEW_HPP
