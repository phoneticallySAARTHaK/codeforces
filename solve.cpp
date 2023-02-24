#include "template.h"

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
