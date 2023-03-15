#include "template.h"

fn solve() -> void {
  let [n] = input<int>();
  auto cards{input<int>(n)};

  auto left{begin(cards)};
  auto right{--end(cards)};
  pair<int, int> sum{};
  int turn{}, current{};
  while (distance(left, right) >= 0) {
    if (*left > * right) {
      current = *left;
      left++;
    }
    else {
      current = *right;
      right--;
    }

    if (even(turn++)) {
      sum.first += current;
    }
    else {
      sum.second += current;
    }
  }
  cout << sum;
}
