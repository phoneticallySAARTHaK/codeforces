#include "template.h"

fn solve() -> void {
  auto [t] = input<int>();
  while (t--) {
    auto [n] = input<int>();
    auto v{input<int>(n)};
    sort(v);
    auto i{1};
    for (; i < n; i++) {
      if (v[i] - v[i - 1] > 1) {
        cout << NO;
        break;
      }
    }
    if (i == n)
     cout << YES;
  }
}
