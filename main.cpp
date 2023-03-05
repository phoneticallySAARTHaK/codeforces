#include "template.h"

void solve();

int main() {
  try {
  fast_io();
  solve();
  cout << endl;
  }
  catch(...) {
    cerr << "Catch-all handler" << endl;
  }
}
