#include "template.h"

void solve() {
  auto [n] = input<int>();
  // i-th person gave gift to vector[i-th] person.
  auto givenTo{input<int>(n)};
  // to find - gift given by, for each person.

  auto seq = iota(1) | take(n);
  for_each(seq, [&givenTo](cauto i) {
    // find the index of 'i' (since its sequential, we can use iota)
    // note: no need to check for end iterator due to problem guarantees
    cout << distance(begin(givenTo), find(givenTo, i)) + 1 << ' ';
  });
}
