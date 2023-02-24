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
    int n{};
    cin >> n;

    int a{}, b{}, load{}, cap{};
    while(cin >> a >> b) {
        cap = max((load += b - a), cap);
    }
    cout << cap;
}
