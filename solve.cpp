#include "template.h"

#define TEST_CASES

inline fn solve()->void {
  let [n] = input<int>();
  let arr{input<int>(n)};
  let [min, max] = minmax(arr);
  output(max - min);
}
