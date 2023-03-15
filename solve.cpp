#include "template.h"

#define TEST_CASES

inline fn solve()->void {
  auto [str] = input<string>();
  cout << ((toupper(str) == "YES"s) ? YES : NO);
}
