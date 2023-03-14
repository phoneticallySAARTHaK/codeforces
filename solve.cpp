#include "template.h"

fn solve() -> void {

  let [n] = input<int>();
  array<vector<int>, 3> skillWiseCount{};

  int i{1};
  for_each(CIN(int), [&skillWiseCount, &i] (let el) mut {
    skillWiseCount[el - 1].push_back(i++);
  });

  auto teamCount = ssize(min(skillWiseCount, {}, [](let& vec) { return ssize(vec);}));
  output(teamCount);

  while (teamCount--) {
    for_each(skillWiseCount, [](auto& vec) {
      cout << vec.back() << ' ';
      vec.pop_back();
    });
    cout << NL;
  }

}

