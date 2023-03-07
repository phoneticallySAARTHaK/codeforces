#include "template.h"

void solve() {
  discard<int>();
  using ist = istream_iterator<pair<int, int>>;
  for_each(ist{cin}, ist{}, [](cauto &p) {
    cauto[a, b] = p;
    cout << (a % b == 0 ? 0 : b - a % b) << endl;
  });
}
