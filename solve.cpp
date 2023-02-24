#include "template.h"

void solve() {
    int n{};
    cin >> n;

    int a{}, b{}, load{}, cap{};
    while(cin >> a >> b) {
        cap = max((load += b - a), cap);
    }
    cout << cap;
}
