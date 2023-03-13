#include "template.h"

fn solve() -> void {
  auto [t] = input<int>();
  while (t--) {
    auto [a, b] = input<int, int>();
    auto [min, max] = minmax(a, b);
    auto diff = max - min;
    output(diff / 10 + static_cast<bool>(diff % 10), NL);
  }
}
