#include "template.h"

void solve() {
  using is_it = istream_iterator<int>;
  discard();
  is_it end{};
  // if the istream_iterator doesn't equal 'end', then '1' was found, hence the
  // problem is hard.
  cout << ((find(is_it(cin), end, 1) != end) ? "HARD" : "EASY");
}
