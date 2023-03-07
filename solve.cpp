#include "template.h"

void solve() {
  auto [n] = input<int>();
  auto v{input<int>(n)};
  auto [min, max] = minmax_element(v);

  auto max_pos {find(v, *max)};
  auto rng = {*min};
  auto min_pos_r {find_end(v, rng)};

  auto minDistanceFromEnd {distance(end(min_pos_r), end(v))};
  auto minDistanceFromBegin{distance(begin(v), begin(min_pos_r))};
  auto maxDistanceFromBegin{distance(begin(v), find(v, *max))};

  if (minDistanceFromBegin < maxDistanceFromBegin) minDistanceFromEnd--;

  cout << maxDistanceFromBegin + minDistanceFromEnd;
}
