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
using std::convertible_to;
using std::cout;
using std::default_sentinel;
using std::default_sentinel_t;
using std::endl;
using std::flush;
using std::getline;
using std::integral;
using std::invocable;
using std::invoke;
using std::ios_base;
using std::is_fundamental;
using std::is_integral;
using std::istream_iterator;
using std::map;
using std::numeric_limits;
using std::ostream_iterator;
using std::pair;
using std::ref;
using std::semiregular;
using std::set;
using std::setw;
using std::signed_integral;
using std::streamsize;
using std::string;
using std::string_view;
using std::tuple;
using std::unreachable_sentinel;
using std::unreachable_sentinel_t;
using std::vector;
using std::operator>>;
using std::operator<<;
//

// using directives
namespace rs = std::ranges;
namespace vs = std::views;
using namespace rs;
using namespace vs;
using namespace std::string_literals;
using namespace std::string_view_literals;
//

// type aliases
using sv = string_view;
using ll = long long int;
//

// macros
#define let auto const
#define mut mutable
#define NL '\n'
#define YES "YES"
#define NO "NO"
#define ALL(x) std::begin(x), std::end(x)
#define RALL(x) std::rbegin(x), std::rend(x)
#define input_assert(is) assert(is.good() && "Input failure");
//

// concepts
template <typename T>
concept istreamable = requires(T x, std::istream& is) { is >> x; };

template <typename T>
concept ostreamable = requires(T x, std::ostream& os) { os << x; };

template <typename T>
concept streamable = (istreamable<T> && ostreamable<T>);
//

// std specializations
namespace std {

template <istreamable T, istreamable U>
inline istream& operator>>(istream& is, const pair<T, U>& p) {
  return is >> p.first >> p.second;
}

template <ostreamable T, ostreamable U>
inline ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << p.first << ' ' << p.second;
}

} // namespace std
//

// Utility functions
  // Functors
[[maybe_unused]] let increment{
    [](signed_integral let p) { return p + 1; }};

[[maybe_unused]] let decrement{
    [](signed_integral let p) { return p - 1; }};

[[maybe_unused]] let truthy{
    [](convertible_to<bool> let p) { return p == true; }};

[[maybe_unused]] let falsy{
    [](convertible_to<bool> let p) { return p == false; }};

[[maybe_unused]] let even{
    [](integral let n) { return n % 2 == 0; }};
//

// Input Utils
inline void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

inline void clear(integral let count = numeric_limits<streamsize>::max(),
                  integral let delim = '\n',
                  std::istream& is = cin) {
  is.ignore(count, delim);
  is.clear();
}

// discard one object of specified type from istream
template <istreamable T = int, signed_integral N = int>
void discard(const N n = 1, std::istream& is = cin) {
  // https://stackoverflow.com/questions/62940748/why-stdistream-iterator-with-multiple-copy-n-always-writes-firs-value
  // This comes down to a perhaps unintuitive fact of istream_iterator:
  //    it doesn't read when you dereference it, but instead when you advance
  //    (or construct) it.
  using ist = istream_iterator<T>;
  advance(ist{is}, n - 1, ist{});
}

template<istreamable T>
auto isr(std::istream& is = cin) {
  using ist = istream_iterator<T>;
  return subrange(ist{is}, ist{});
}

template<ostreamable T>
auto osr(std::ostream& os = cout) {
  using ost = ostream_iterator<T>;
  return subrange(ost{os}, ost{});
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
  apply([&is](auto& ...args) { (is >> ... >> args); }, tpl);
  input_assert(is);
  return tpl;
}

// Read 'n' objects of type 'T', and return a vector
template <istreamable T, typename Proj = std::identity>
vector<T> input(integral let size, Proj proj = {}, std::istream& is = cin) {
  vector<T> vec(size);
  for_each(vec, [&is, &proj](auto& el) mut {
    is >> el;
    invoke(proj, el);
  });
  input_assert(is);
  return vec;
}

// Read all input as string
template <rd_mode mode = rd_mode::buffer>
string input(integral let size, std::istream& is = cin) {
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
  } while (n /= 10);
  return v;
}

vector<int> splitDigits(integral auto n) {
  auto v{splitDigitsReversed(n)};
  rs::reverse(v);
  return v;
}
//

#endif // TEMPLATE_H
