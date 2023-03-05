#include "template.h"

void solve() {
  auto [n, h] = getInput<int, int>();

  auto heights{getInput<int>(n)};

  cout << accumulate(
      begin(heights), end(heights), 0,
      [&h](cauto acc, cauto el) { return acc + (el <= h ? 1 : 2); });
}
