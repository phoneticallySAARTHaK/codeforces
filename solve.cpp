#include "template.h"

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