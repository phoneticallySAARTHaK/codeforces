#include "template.h"

fn solve() -> void {
  let max{5};
  let [n, k] = input<int, int>();
  let exp{input<int>(n)};
  let eligible = accumulate(ALL(exp), 0, [maxVal = max - k](let acc, let p) {
    return (acc + bool(p <= maxVal));
  });
  cout << (eligible / 3);
}
