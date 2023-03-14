#include "template.h"

fn solve() -> void {
  auto [t] = input<int>();
  while(t--) {
    auto [str] = input<string>();
    cout << str[0];
    auto last = ssize(str) - 1;
    for (int i{1}; i < last; i += 2) {
        cout << str[i];
    }
    cout << str.back() << NL;
  }
}
