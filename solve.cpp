#include "template.h"

void solve() {
  cauto [n] = input<int>();
  vector<bool> levels(n, false);
  using ist = istream_iterator<int>;
  for_each(ist{cin}, ist{}, [&levels](cauto el) { levels[el - 1] = true; });
  cout << (any_of(levels, falsy) ? "Oh, my keyboard!" : "I become the guy." ) ;
}
