#include "template.h"

void solve() {
  cauto [n] = input<int>();
  using ist = istream_iterator<int>;
  cauto vol{accumulate(ist(cin), ist{}, 0.0)};
  cout << vol / n;
}
