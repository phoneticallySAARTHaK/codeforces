#include "template.h"

fn solve() -> void {
  auto pos{input<int>(3)};
  auto [min, max] = minmax_element(pos);
  cout << *max - *min;
}
