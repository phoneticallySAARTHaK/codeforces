#include "template.h"

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
