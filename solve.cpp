#include "template.h"

fn solve()->void {
  auto [t] = input<int>();
  let isLiked = [](let n) { return !(n % 3 == 0 || n % 10 == 3); };
  while (t--) {
    let[k] = input<int>();
    auto seq = iota(1) | filter(isLiked) | take(k);
    cout << max(seq) << NL;
  }
}
