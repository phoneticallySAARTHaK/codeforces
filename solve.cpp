#include "template.h"

fn solve() -> void {
  auto [n] = input<int>();
  if (even(n)) {
    cout << 4 << ' ' << n - 4;
  } else {
    cout << 9 << ' ' << n - 9;
  }
}
