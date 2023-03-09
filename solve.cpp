#include "template.h"

enum direction {
  left, right
};

fn solve() -> void {
  auto [n, m] = input<int, int>();
  vector board(n, string(m, '#'));

  direction dir{};
  let func = [](char& ch) mut { ch = '.'; };

  for (int i{1}, iter{1}; i < n; i += 2, iter++) {
    dir = even(iter) ? left : right;

    if (dir == right)
      for_each(begin(board[i]), --end(board[i]), func);
    else
      for_each(++begin(board[i]), end(board[i]), func);
  }

  for_each(board, [](let& str) { cout << str << '\n'; });
}
