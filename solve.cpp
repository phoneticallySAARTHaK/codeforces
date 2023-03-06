#include "template.h"

void solve() {
  cauto [n] = input<int>();

  sv hate{"I hate"};
  sv love{"I love"};
  sv that{" that "};
  sv it{" it "};

  for (auto i{1}; i < n; i++) {
    cout << (isEven(i) ? love : hate) << that;
  }
  cout << (isEven(n) ? love : hate) << it;
}
