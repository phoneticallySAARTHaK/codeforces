#include "template.h"

void solve() {
  cauto [n] = input<int>();
  vector<bool> levels(n, false);
  using ist = istream_iterator<int>;
  cauto flag = [&levels](cauto el) { levels[el - 1] = true; };

  for (auto i : iota(0, 2)) {
    auto [s] = input<int>();
    auto v{input<int>(s)};
    for_each(v, flag);
  }


  cout << (any_of(levels, falsy) ? "Oh, my keyboard!" : "I become the guy.");
}
