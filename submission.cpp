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

// a -> triples every year
// b -> doubles every year
// pre: a <= b
// a*3^n > b*2^n
void solve() {
    int a, b;
    cin >> a >> b;

    int years{};
    while (++years) {
        a *= 3;
        b *= 2;
        if (a > b) {
            break;
        }
    }
    cout << years;
}
