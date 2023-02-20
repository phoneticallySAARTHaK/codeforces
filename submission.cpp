#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define YES "YES"
#define NO "NO"
#define ll long long

inline void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

inline void clearCin(int delim = '\n') {
    cin.ignore(numeric_limits<streamsize>::max(), delim);
    cin.clear();
}


void solve();

int main()
{
    fast_io();
    solve();
    cout << endl;
}

auto getTotalCost(const auto k, const auto w) {
    return k * ((w * (w + 1)) / 2);
}

void solve() {
    ll k, n, w;
    cin >> k >> n >> w;

    const auto totalCost{getTotalCost(k, w)};
    const auto toBorrow {n > totalCost ? 0 : totalCost - n};

    cout << toBorrow;
}
