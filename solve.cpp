#include "template.h"

fn solve() -> void {
  discard<int>();
  int max{}, min{}, n{};
  cin >> n;
  max = min = n;

  auto tracker = [] (int& max, int& min, let n) mut {
    if (n > max) {
      max = n;
      return true;
    } else if (n < min) {
      min = n;
      return true;
    }
    return false;
  };

  cout << accumulate(CIN(int), 0, [&](let acc, let n) mut {
    if (tracker(max, min, n)) {
      return acc + 1;
    }
      return acc;
  });
}
