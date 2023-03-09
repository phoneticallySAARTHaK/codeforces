#include "template.h"

fn solve() -> void {
  discard<int>();
  cout << accumulate(CIN(int), 0, [manpw = 0](let acc, let ev) mut {
    if (ev == -1 && manpw == 0)
      return acc + 1;
    else {
      manpw += ev;
      return acc;
    }
  });
}
