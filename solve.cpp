#include "template.h"

fn solve() -> void {
  int v[]{100, 20, 10, 5, 1};
  auto [n] = input<int>();

  cout << accumulate(ALL(v), 0, [money = n](let acc, let bill) mut {
    auto t = acc + (money / bill);
    money %= bill;
    return t;
  });
}
