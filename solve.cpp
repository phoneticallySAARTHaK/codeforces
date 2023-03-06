#include "template.h"

void solve() {
  cauto [n1, n2] = input<string, string>();
  auto size(ssize(n1));
  string res;
  res.reserve(size);
  for (auto i{0}; i < size; i++) {
    res += (n1[i] != n2[i]) + '0';
  }
  cout << res;
}
