#include "template.h"

fn solve() -> void {
  auto [a, b] = input<int, int>();
  auto same = (max(a, b) - min(a, b))/ 2;
  cout << min(a, b) << ' ' << same;
}
