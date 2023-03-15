#include "template.h"

// #define TEST_CASES

inline fn solve()->void {
  let[cals, strips] = input<array<int, 4>, string>();
  output(accumulate(ALL(strips), 0, [&cals](let acc, let ch) {
    return acc + cals[ch - '0' - 1];
  }));
}
