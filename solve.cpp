#include "template.h"

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
