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

#define ANTON_WON "Anton"
#define DANIK_WON "Danik"
#define TIE "Friendship"


enum player {
    Anton = 'A',
    Danik = 'D',
};

void solve() {
    int x;
    string series;
    cin >> x >> series;

    int antonFreq{}, DanikFreq{};
    for (const auto gameWinner : series) {
        (gameWinner == player::Anton) ? antonFreq++ : DanikFreq++;
    }

    if (antonFreq == DanikFreq) {
        cout << TIE;
    }
    else if (antonFreq > DanikFreq) {
        cout << ANTON_WON;
    }
    else {
        cout << DANIK_WON;
    }
}
