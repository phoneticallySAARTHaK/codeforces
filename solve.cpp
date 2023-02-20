#include "template.h"

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
