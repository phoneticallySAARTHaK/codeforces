#include "template.h"

// Make a State Machine for storing state of the magnet string
struct FSM {
  char poles[2]{};
  int parts{1};

  void operator+=(const char ch) {
    poles[0] = poles[1];
    poles[1] = ch;
    if (poles[0] == poles[1]) {
      parts++;
     }
  }

  operator int() {
    return parts;
  }
};

void solve() {
  discard<int>();
  FSM state{};
  using ist = istream_iterator<char>;
  for_each(ist{cin}, ist{},
           [&state](cauto ch) { state += ch; });
  cout << state;
}
