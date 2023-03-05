#ifndef TESTS_H
#define TESTS_H

#include "template.h"


// getInput function, move vs copy test.
// https://stackoverflow.com/questions/45694560/arguments-to-tuple-are-copied-instead-of-moved-when-returning-the-tuple-from-a-f
struct Bar {
  int a;
  string b{"Bar"};
  Bar() { cout << "default\n"; }
  Bar(int a, const string &b) : a{a}, b{b} { cout << "direct\n"; }
  Bar(int a, string &&b) : a{a}, b{std::move(b)} { cout << "direct move b\n"; }
  Bar(const Bar &other) : a{other.a}, b{other.b} { cout << "const copy\n"; }
  Bar(Bar &&other) : a{std::move(other.a)}, b{std::move(other.b)} {
    cout << "move\n";
  }
  Bar &operator=(const Bar &other) {
    a = other.a;
    b = other.b;
    cout << "const assign\n";
    return *this;
  }

  Bar &operator=(Bar &&other) {
    a = std::move(other.a);
    b = std::move(other.b);
    cout << "move assign\n";
    return *this;
  }

  operator int() { return a; }

  friend std::istream &operator>>(std::istream &is, Bar &b) { cout << "Bar cin\n"; return is >> b.a; }
};

void testGetInput() {
  auto [n, i] = getInput<int, Bar>();
  cout << n << i;
}

#endif // TESTS_H
