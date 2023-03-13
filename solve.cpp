#include "template.h"

fn padZeroes(auto c) {
  while (c--)
    cout << '0';
}

fn solve()->void {
  auto [t] = input<int>();
  while (t--) {
    auto [n] = input<string>();
    let zeroCount{count(n, '0')};

    cout << (ssize(n) - zeroCount) << '\n';
    for_each(n, [power = ssize(n) - 1](let d) mut {
      if (d == '0') {
        power--;
        return;
      }

      cout << d;
      padZeroes(power);
      power--;
      cout << ' ';
    });
    cout << '\n';
  }
}
