#ifndef TEMPLATE_H
#define TEMPLATE_H

// Headers
#include <bits/stdc++.h>
//

// using declarations
using std::accumulate;
using std::apply;
using std::array;
using std::cerr;
using std::cin;
using std::common_type_t;
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
using std::make_pair;
using std::make_tuple;
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
using std::same_as;
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
#define fn auto
#define NL '\n'
#define YES "YES\n"
#define NO "NO\n"
#define ALL(x) std::begin(x), std::end(x)
#define RALL(x) std::rbegin(x), std::rend(x)
#define input_assert(is) assert(is.good() && "Input failure");
#define CIN(type) istream_iterator<type>(cin), istream_iterator<type>()
#define OST(R) ostream_iterator<range_value_t<R>>
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
inline istream& operator>>(istream& is, pair<T, U>& p) {
  return is >> p.first >> p.second;
}

template <ostreamable T, ostreamable U>
inline ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << p.first << ' ' << p.second;
}

template <istreamable T, size_t N>
inline istream& operator>>(istream& is, array<T, N>& arr) {
  ranges::for_each(arr, [&is](auto& el) mut { is >> el; });
  return is;
}

} // namespace std
//

// Utility functions
inline bool operator==(const string& str, const char ch) {
  return size(str) == 1 && str[0] == ch;
}

  // Functors
constexpr auto increment{
    [](signed_integral let p) { return p + 1; }};

constexpr auto decrement{
    [](signed_integral let p) { return p - 1; }};

constexpr auto truthy{
    [](convertible_to<bool> let p) { return static_cast<bool>(p) == true; }};

constexpr auto falsy{
    [](convertible_to<bool> let p) { return static_cast<bool>(p) == false; }};

constexpr auto even{
    [](integral let n) { return n % 2 == 0; }};
//

// Input Utils
inline void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

inline void clear(integral let count = numeric_limits<streamsize>::max(),
                  const char delim = '\n',
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
  auto it = ist{is};
  advance(it, n - 1, ist{});
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

// https://stackoverflow.com/a/38894158
template <size_t I,typename T>
struct tuple_n{
    template< typename...Args> using type = typename tuple_n<I-1, T>::template type<T, Args...>;
};

template <typename T>
struct tuple_n<0, T> {
    template<typename...Args> using type = std::tuple<Args...>;
};

template <size_t I,typename T>  using tuple_of = typename tuple_n<I,T>::template type<>;

template<size_t N, istreamable T>
auto input(std::istream& is = cin) {
  tuple_of<N, T> tpl;
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

namespace tokens {

inline string input(std::istream& is = cin) {
  string text, str;
  while (is >> str) text += str;
  return text;
}

inline string input(sv delim = ""sv, std::istream& is = cin) {
  input_assert(is);
  string text, str;

  while (is >> str) {
    text += str;
    text += delim;
  };

  auto excess = ssize(delim);
  while (excess--) text.pop_back();

  return text;
}


inline string input(signed_integral auto count, std::istream& is = cin) {
  string text, str;
  while (count-- && is >> str) text += str;
  return text;
}

inline string input(signed_integral auto count, sv delim = ""sv, std::istream& is = cin) {
  input_assert(is);
  string text, str;

  while (count-- && is >> str) {
    text += str;
    text += delim;
  };

  auto excess = ssize(delim);
  while (excess--) text.pop_back();

  return text;
}
} // namespace tokens

namespace line {
struct Flags {
  char delim{'\n'};
  bool no_trim{false};
};

inline string input(std::istream &is = cin) {
  string text;
  getline(is >> std::ws, text);
  return text;
}

inline string input(const Flags flags, std::istream &is = cin) {
  string text;
  if (!flags.no_trim) is >> std::ws;
  getline(is, text, flags.delim);
  return text;
}
} // namespace line
  //

// Output utils
template <range R>
inline std::ostream& output(R& r, const char* delim = " ", std::ostream& os = cout) {
  copy(r, ostream_iterator<range_value_t<R>>(os, delim));
  return  os;
}

template <range R>
inline std::ostream& output(R& r, const char delim, std::ostream& os = cout) {
  copy(r, ostream_iterator<range_value_t<R>>(os, string{delim}.c_str()));
  return os;
}

template <range R, ostreamable E>
inline std::ostream& output(R& r, const char* delim, const E& end, std::ostream& os = cout) {
  copy(r, ostream_iterator<range_value_t<R>>(os, delim));
  return  os << end;
}

template <range R, ostreamable E>
inline std::ostream& output(R& r, const char delim, const E& end, std::ostream& os = cout) {
  copy(r, ostream_iterator<range_value_t<R>>(os, string{delim}.c_str()));
  return os << end;
}

template <ostreamable ...T>
inline std::ostream& output(const T&... args) {
  invoke([](let& ...args) {
     (... , (cout << args, cout << ' '));
  }, args...);
  return cout << NL;
}



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

inline int alphIndex(const int ch) {
  assert(isupper(ch) || islower(ch));
  return ch - (isupper(ch) ? 'A' : 'a');
}

// Returns variables with given value as a tuple
template <typename ...T>
tuple<T...> init(const common_type_t<T...>& val) {
  tuple<T...> tpl;
  apply([&val](auto& ...args) { (args = ... = val); }, tpl);
  return tpl;
}

template <typename ...T>
void assign(const common_type_t<T...>& val, T&... args) {
  invoke([&val](auto& ...args) { (args = ... = val); }, args...);
}


// string utils
inline auto toupper(string& str) {
  for_each(str, [](auto& ch) { ch = std::toupper(ch);} );
  return str;
}

inline auto tolower(string& str) {
  for_each(str, [](auto& ch) { ch = std::tolower(ch);} );
  return str;
}

template <typename T>
concept non_modifiable_string =
    same_as<const char *, T> || same_as<string_view, T>;

inline auto toupper(const non_modifiable_string auto str) {
  string s{str};
  return toupper(s);
}

inline auto tolower(const non_modifiable_string auto str) {
  string s{str};
  return tolower(s);
}

inline auto toupper(const string& str) {
  return toupper(string_view{str});
}

inline auto tolower(const string& str) {
  return tolower(string_view{str});
}

template<typename T, typename U>
concept subtractable = requires (T t, U u) { t - u;};

template <typename T,typename U>
requires subtractable<T, U>
auto pair_diff(const pair<T, U>& p) {
  return p.first - p.second;
}
//

#endif // TEMPLATE_H
