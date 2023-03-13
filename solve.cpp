#include "template.h"

fn solve() -> void {
  auto v{input<int>(4)};
  sort(v, greater{});
  auto numbers = v
                   | drop(1)
                   | vs::transform([abc = v.front()]
                               (let n) mut { return abc - n; });
  copy(numbers, ostream_iterator<int>(cout, " "));
}
