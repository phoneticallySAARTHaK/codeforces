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

// STL - list.unique()
auto removeDuplicates(auto& stones) {
    auto last{end(stones)};
    auto it1{begin(stones)};
    auto it2{it1};

    int moves{};

    while(++it2 != last) {
        if (*it1 == *it2) {
            stones.erase(it1);
            moves++;
        }
        it1 = it2;
    }
    return moves;
}

void solve() {
    int n{};
    string str;
    cin >> n >> str;

    list<char> stones{begin(str), end(str)};

    cout << removeDuplicates(stones);
}
