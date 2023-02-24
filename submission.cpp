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
    string ber, bir;
    cin >> ber >> bir;

    auto ber_it = cbegin(ber);
    auto bir_rit = crbegin(bir);

    const auto ber_end = cend(ber);
    const auto bir_rend = crend(bir);

    auto isEqual{true};
    for (; ber_it != ber_end && bir_rit != bir_rend; ber_it++, bir_rit++) {
        if (*bir_rit != *ber_it) {
            isEqual = false;
            break;
        }
    }

    cout << (isEqual ? YES : NO);
}
