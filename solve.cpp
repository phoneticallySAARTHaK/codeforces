#include "template.h"

fn solve() -> void {
  auto [n, k, l, c, d, p, nl, np] =
      input<int, int, int, int, int, int, int, int>();
  vector v{(k * l) / nl, (c * d), p / np };
  cout << *min_element(v) / n;
}
