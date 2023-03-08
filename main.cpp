#include "template.h"

void solve();

fn main() -> int {
  try {
    fast_io();
    solve();
    cout << endl;
  } catch (...) {
    cerr << "Catch-all handler" << endl;
  }
}
