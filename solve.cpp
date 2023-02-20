#include "template.h"

void solve() {
    ll x;
    cin >> x;

    const auto forwardBy5 {x / 5};
    const auto remaining {x % 5};

    // hack to convert int > 1 to 1, and 0 to 0.
    cout << forwardBy5 + bool(remaining);
}
