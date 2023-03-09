#include "template.h"

fn freqFill(auto& arr, let& str) {
  for_each(str, [&arr](let ch) mut { arr[alphIndex(ch)]++; });
}

fn solve() -> void {
  auto [s1, s2, s3] = input<string, string, string>();
  array<int, 26> original{}, jumbled{};

  for (let& str : {s1, s2}) freqFill(original, str);
  freqFill(jumbled , s3);

  for (int i{}; let f : original) {
    if (jumbled[i] != f) {
      cout << NO;
      return;
    }
    i++;
  }
  cout << YES;
}
