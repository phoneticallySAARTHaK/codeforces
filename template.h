#pragma once
#include <bits/stdc++.h>
using std::apply;
using std::cerr;
using std::cin;
using std::cout;
using std::conjunction;
using std::integral;
using std::ios_base;
using std::is_fundamental;
using std::is_integral;
using std::istream_iterator;
using std::map;
using std::numeric_limits;
using std::pair;
using std::setw;
using std::streamsize;
using std::string;
using std::ref;
using std::tuple;
using std::vector;
using std::semiregular;
using std::signed_integral;

namespace rs = std::ranges;
namespace vs = std::views;
using namespace rs;
using namespace vs;

#define endl '\n'
#define YES "YES"
#define NO "NO"
#define ll long long
#define cauto const auto

inline void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

inline void clear(int delim = '\n') {
  cin.ignore(numeric_limits<streamsize>::max(), delim);
  cin.clear();
}

template <typename T = int, typename N = int>
  requires is_fundamental<T>::value && is_integral<N>::value
void discard(N n = 1) {
  // https://stackoverflow.com/questions/62940748/why-stdistream-iterator-with-multiple-copy-n-always-writes-firs-value
  // This comes down to a perhaps unintuitive fact of istream_iterator:
  //    it doesn't read when you dereference it, but instead when you advance (or construct) it.
  auto it{istream_iterator<T>(cin)};
  advance(it, n - 1, istream_iterator<T>{});
}

// Fold expression, parameter
// packshttps://www.scs.stanford.edu/~dm/blog/param-pack.html
// (See testGetInput for usage)
template <semiregular ...T>
auto getInput() {
  tuple<T...> tpl;
  apply([](auto& ...args) { (cin >> ... >> args); }, tpl);

  assert(cin.good() && "Input failure");

  return tpl;
}

template<semiregular T>
vector<T> getInput(signed_integral auto n) {
  vector<T> vec(n);
  copy_n(istream_iterator<T>(cin), n, begin(vec));
  return vec;
}




