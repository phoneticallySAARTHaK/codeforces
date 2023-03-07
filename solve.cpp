#include "template.h"

void solve() {
  discard<int>();
  vector<bool> v(26);
  for_each(isr<char>(), [&v](let ch) mut { v[tolower(ch) - 'a'] = true; });
  cout << (any_of(v, falsy) ? NO : YES);
}
