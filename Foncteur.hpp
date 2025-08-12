#include <string>
using namespace std;

class CompareLongueur {
public:
  bool operator()(const string &a, const string &b) const {
    return a.length() < b.length();
  }
};
