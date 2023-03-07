#include "template.h"

void solve() {
  using ist = istream_iterator<int>;
  cout << 4 - ssize(set<int>{ist{cin}, ist{}});
}
