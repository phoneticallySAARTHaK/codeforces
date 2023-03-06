#include "template.h"

void solve() {
  cauto [n] = input<ll>();
  cauto sign {isEven(n) ? 1 : -1};
  cout << sign * ( n / 2 + n % 2);
}
