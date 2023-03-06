#include "template.h"

using Room = pair<int, int>;

inline bool isLivable(const Room& r) {
  #define living first
  #define capacity second
  return r.capacity - r.living >= 2;
}

void solve() {
  auto [n] = input<int>();
  auto Rooms{input<Room>(n)};
  cout << accumulate(all(Rooms), 0, [](cauto acc, cauto& i) {
    return acc + static_cast<int>(isLivable(i));
  });
}
