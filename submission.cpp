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

void solve() {
    ll x;
    cin >> x;

    const auto forwardBy5 {x / 5};
    const auto remaining {x % 5};

    // hack to convert int > 1 to 1, and 0 to 0.
    cout << forwardBy5 + bool(remaining);
}
