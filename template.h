#pragma once

// Headers
#include <bits/stdc++.h>
//

// using declarations
using std::accumulate;
using std::apply;
using std::cerr;
using std::cin;
using std::conjunction;
using std::cout;
using std::integral;
using std::ios_base;
using std::is_fundamental;
using std::is_integral;
using std::istream_iterator;
using std::map;
using std::numeric_limits;
using std::pair;
using std::ref;
using std::semiregular;
using std::set;
using std::setw;
using std::signed_integral;
using std::streamsize;
using std::string;
using std::tuple;
using std::unreachable_sentinel;
using std::vector;
using std::operator>>;
using std::operator<<;
//

// using directives
namespace rs = std::ranges;
namespace vs = std::views;
using namespace rs;
using namespace vs;
//

// #defines
#define endl '\n'
#define YES "YES"
#define NO "NO"
#define ll long long
#define cauto const auto
#define all(x) std::begin(x), std::end(x)
//

// concepts
template <typename T>
concept istreamable = requires(T x, std::istream &is) { is >> x; };

template <typename T>
concept ostreamable = requires(T x, std::ostream &os) { os << x; };

template <typename T>
concept streamable = (istreamable<T> && ostreamable<T>);
//

// std specializations
namespace std {

template <istreamable T>
inline istream &operator>>(istream &is, pair<T, T> &p) {
  return is >> p.first >> p.second;
}

template <ostreamable T>
inline ostream &operator<<(ostream &os, pair<T, T> &p) {
  return os << p.first << p.second;
}

} // namespace std
//

// utility functions
inline void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

inline void clear(int delim = '\n') {
  cin.ignore(numeric_limits<streamsize>::max(), delim);
  cin.clear();
}

template <istreamable T = int, signed_integral N = int>
void discard(N n = 1) {
  // https://stackoverflow.com/questions/62940748/why-stdistream-iterator-with-multiple-copy-n-always-writes-firs-value
  // This comes down to a perhaps unintuitive fact of istream_iterator:
  //    it doesn't read when you dereference it, but instead when you advance
  //    (or construct) it.
  istream_iterator<T> it{cin};
  advance(it, n - 1, istream_iterator<T>{});
}

// Fold expression, parameter
// packshttps://www.scs.stanford.edu/~dm/blog/param-pack.html
// (See testGetInput for usage)
template <istreamable ...T>
auto input() {
  tuple<T...> tpl;
  apply([](auto &...args) { (cin >> ... >> args); }, tpl);
  assert(cin.good() && "Input failure");
  return tpl;
}

template <semiregular T> vector<T>
input(signed_integral auto n) {
  vector<T> vec(n);
  copy_n(istream_iterator<T>(cin), n, begin(vec));
  assert(cin.good() && "Input failure");
  return vec;
}

vector<int> splitDigitsReversed(integral auto n) {
  vector<int> v;
  do {
    v.push_back(n % 10);
  }
  while (n /= 10);
  return v;
}

vector<int> splitDigits(integral auto n) {
  auto v{splitDigitsReversed(n)};
  std::reverse(begin(v), end(v));
  return v;
}
//
