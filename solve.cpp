#include "template.h"

auto getTotalCost(const auto k, const auto w) {
    return k * ((w * (w + 1)) / 2);
}

void solve() {
    ll k, n, w;
    cin >> k >> n >> w;

    const auto totalCost{getTotalCost(k, w)};
    const auto toBorrow {n >= totalCost ? 0 : totalCost - n};

    cout << toBorrow;
}
