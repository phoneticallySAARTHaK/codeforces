#include "template.h"

bool isUnique(integral auto n) {
  auto digits{splitDigitsReversed(n)};
  set<int> uniqDigits{all(digits)};
  return ssize(digits) == ssize(uniqDigits);
}

void solve() {
  auto [y] = getInput<int>();
  cout << *find_if(iota(y + 1), [](auto n) { return isUnique(n); });
}
