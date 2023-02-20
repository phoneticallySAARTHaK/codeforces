#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define YES "YES"
#define NO "NO"

void fast_io();
void clearCin(int delim = '\n');
void solve();

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void clearCin(int delim) {
    cin.ignore(numeric_limits<streamsize>::max(), delim);
    cin.clear();
}
