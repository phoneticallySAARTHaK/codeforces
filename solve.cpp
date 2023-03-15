#include "template.h"

fn solve() -> void {
  auto [t] = input<int>();
  while (t--) {
    auto dist{input<int>(4)};
    let a = dist[0];
    sort(dist, greater{});
    output(distance(begin(dist), find(dist, a)));
  }
}
