#include "template.h"

void solve() {
  string line;
  getline(cin, line);
  auto r = line | filter(isalpha);
  cout << ssize(set<char>{r.begin(), r.end()});
}
