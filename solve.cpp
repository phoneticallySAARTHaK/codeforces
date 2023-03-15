#include "template.h"

fn solve() -> void {
  auto [t] = input<int>();
  while (t--) {
    let [x, y, n] = input<3, int>();
    let rem {y % x};
    let m{ (n - rem) / x};
    output(m * x + rem);
  }
}
