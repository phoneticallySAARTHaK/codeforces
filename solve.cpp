#include "template.h"

#define TEST_CASES

inline fn solve()->void {
  let [n, days] = input<int, string>();
  array<bool, 26> alphabets{};

  auto prev{days[0]};
  alphabets[alphIndex(prev)] = true;
  for (int i{1}; i < ssize(days); prev = days[i], i++) {
    let day = days[i];
    if (prev == day) continue;

    if (alphabets[alphIndex(day)]) {
      cout << NO;
      return;
    }

    alphabets[alphIndex(day)] = true;
  }

  cout << YES;
}
