#include "template.h"

void solve();

fn main() -> int {
  try {
    fast_io();
#ifdef TEST_CASES
    auto [t] = input<int>();
    while (t--) solve();
#else
    solve();
#endif

    cout << endl;
  } catch (...) {
    cerr << "Catch-all handler" << endl;
  }
}
