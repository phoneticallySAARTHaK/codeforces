#include "template.h"

fn solve()->void {
  discard<int>();
  using round_t = pair<int, int>;
  let [mis, chris] = accumulate(CIN(round_t), make_pair(0, 0), [](let acc, let p) {
    if (p.first > p.second) {
      return make_pair(acc.first + 1, acc.second);
    } else if (p.first < p.second) {
      return make_pair(acc.first, acc.second + 1);
    } else {
      return acc;
    }
  });

  if (mis > chris) {
    cout << "Mishka";
  }
  else if (chris > mis) {
    cout << "Chris";
  }
  else {
    cout << "Friendship is magic!^^";
  }
}
