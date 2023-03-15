#include "template.h"

#define TEST_CASES

inline void solve() {
  let[n] = input<int>();
  auto arr{input<int>(n)};
  auto mismatches{0}, balance{0};

  for_each(arr, [&mismatches, &balance, i = 0](let a) mut {
    if (!((even(i) && even(a)) || (!even(i) && !even(a)))) {
      mismatches++;
      balance += even(i) ? 1 : -1;
    }
    i++;
  });
  output(balance == 0 ? mismatches / 2 : -1);
}
