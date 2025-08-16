#ifndef SLIDEVIEW_HPP
#define SLIDEVIEW_HPP

#define SLIDE_STRUCT SlideView *, ClicZone

#include "ClicZone.hpp"
#include "raylib.h"
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

class SlideView {
public:
  SlideView();
  SlideView(std::string imagePath);
  ~SlideView();

  std::map<SLIDE_STRUCT> getSlideMap() const;
  std::string getSlideImagePath() const;
  std::vector<SlideView *> getPriorityList();
  void print(std::ostream &flux);

  void addSlideMap(std::pair<SLIDE_STRUCT> slide);
  void rmSlideMap(SlideView &slide);
  void link(std::pair<SLIDE_STRUCT> slide, ClicZone cliczone);
  void unLink(SlideView *slide);

  SlideView *getTheSlideViewTargerted(Vector2 touchPosition);

protected:
  void sortPriorityList();

private:
  std::string const m_imagePath;
  std::map<SLIDE_STRUCT> m_slideMap;
  std::vector<SlideView *> m_priorityList;
};

bool operator<(std::pair<SLIDE_STRUCT> const &a,
               std::pair<SLIDE_STRUCT> const &b);
bool operator>(std::pair<SLIDE_STRUCT> const &a,
               std::pair<SLIDE_STRUCT> const &b);
std::ostream &operator<<(std::ostream &flux, SlideView &slide);
#endif //! SLIDEVIEW_HPP
