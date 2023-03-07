#ifndef TEMPLATE_H
#define TEMPLATE_H

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
using std::invoke;
using std::invocable;
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
using std::unreachable_sentinel_t;
using std::unreachable_sentinel;
using std::default_sentinel_t;
using std::default_sentinel;
using std::vector;
using std::operator>>;
using std::operator<<;
using std::operator""s;
using std::operator""sv;
using std::string_view;
using sv = string_view;
using std::convertible_to;
//

// using directives
namespace rs = std::ranges;
namespace vs = std::views;
using namespace rs;
using namespace vs;
using ll = long long int;
//

// #defines
#define endl '\n'
#define YES "YES"
#define NO "NO"
#define cauto const auto
#define ALL(x) std::begin(x), std::end(x)
#define input_assert(is) assert(is.good() && "Input failure");
#define size_type_t const signed_integral auto
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

// Utility functions
  // Functors
[[maybe_unused]] constexpr auto increment{
    [](signed_integral auto p) { return ++p; }};

[[maybe_unused]] constexpr auto decrement{
    [](signed_integral auto p) { return --p; }};

[[maybe_unused]] constexpr auto truthy {
  [] (convertible_to<bool> auto p) { return p == true; }
};

[[maybe_unused]] constexpr auto falsy {
  [] (convertible_to<bool> auto p) { return p == false; }
};

inline constexpr bool isEven(integral auto n) { return n % 2 == 0; }
//

// Input Utils
inline void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

inline void clear(auto count = numeric_limits<streamsize>::max(),
                  int delim = '\n',
                  std::istream& is = cin) {
  is.ignore(count, delim);
  is.clear();
}

template <istreamable T = int, signed_integral N = int>
void discard(N n = 1, std::istream& is = cin) {
  // https://stackoverflow.com/questions/62940748/why-stdistream-iterator-with-multiple-copy-n-always-writes-firs-value
  // This comes down to a perhaps unintuitive fact of istream_iterator:
  //    it doesn't read when you dereference it, but instead when you advance
  //    (or construct) it.
  istream_iterator<T> it{is};
  advance(it, n - 1, istream_iterator<T>{});
}

enum class rd_mode {
  buffer,
  vector,
};

// Fold expression, parameter packs
// https://www.scs.stanford.edu/~dm/blog/param-pack.html
// Returns a tuple, which can be destructured. (See testGetInput for usage)
template <istreamable ...T>
tuple<T...> input(std::istream& is = cin) {
  tuple<T...> tpl;
  apply([&is](auto &...args) { (is >> ... >> args); }, tpl);
  input_assert(is);
  return tpl;
}

// Read 'n' objects of type 'T', and return a vector
template <istreamable T, typename Proj = std::identity>
vector<T> input(size_type_t size, Proj proj = {}, std::istream& is = cin) {
  vector<T> vec(size);
  for_each(vec, [&is, &proj](auto &el) { is >> el; invoke(proj, el);});
  input_assert(is);
  return vec;
}

// Read all input as string
template <rd_mode mode = rd_mode::buffer>
string input(size_type_t size, std::istream& is = cin) {
  string text, str;
  text.reserve(size);
  while (ssize(text) < size && is >> str)
    text += str;
  return text;
}
  //

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

#endif // TEMPLATE_H

void solve();

int main() {
  try {
    fast_io();
    solve();
    cout << endl;
  } catch (...) {
    cerr << "Catch-all handler" << endl;
  }
}

void solve() {
  cauto [n] = input<int>();
  vector<bool> levels(n, false);
  using ist = istream_iterator<int>;
  cauto flag = [&levels](cauto el) { levels[el - 1] = true; };

  for (auto i : iota(0, 2)) {
    auto [s] = input<int>();
    auto v{input<int>(s)};
    for_each(v, flag);
  }


  cout << (any_of(levels, falsy) ? "Oh, my keyboard!" : "I become the guy.");
}
