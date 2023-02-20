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
    string word;
    cin >> word;

    int lowerCaseFreq{}, upperCaseFreq{};
    for (const auto letter : word) {
        isupper(letter) ? upperCaseFreq++ : lowerCaseFreq++;
    }

    for (auto& letter : word) {
        letter = (upperCaseFreq > lowerCaseFreq) ? toupper(letter) : tolower(letter);
    }

    cout << word;
}
