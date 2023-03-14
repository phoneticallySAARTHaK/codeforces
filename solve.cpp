#include "template.h"

fn solve() -> void {
  let [n] = input<int>();
  int max{};

  auto exp{input<int>(n, [&max](let p) mut { max = max < p ? p : max; })};

  output(accumulate(ALL(exp), 0,
                    [max](let acc, let e) { return acc + (max - e); }));
}
