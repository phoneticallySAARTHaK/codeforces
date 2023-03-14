#include "template.h"

fn solve() -> void {
  auto [t] = input<int>();
  while (t--) {
    let [n] = input<int>();
    auto arr{input<int>(n)};
    auto dist{arr[0]}, i{1};

    for (; i < n - 1; i++) {
      if (dist != arr[i]) {
        // dist is equal to last, but dist is not equal to ith element,
        // means ith element is distinct
        cout << ((dist == arr.back()) ? i + 1 : 1) << NL;
        break;
      }
    }
    // else, if no distinct element was found, it's the last
    if (i == n - 1) cout << n << NL;
  }
}
