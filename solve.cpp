#include "template.h"


using Uniform = pair<int, int>;
#define home first
#define guest second


fn solve() -> void {
  let [n] = input<int>();
    let uniforms{input<Uniform>(n)};
    int common{};

    for (let hostTeam : iota(0, n)) {
      for (let guestTeam : iota(0, n)) {
        if (hostTeam == guestTeam) {
          continue;
        }

        if (uniforms[hostTeam].home == uniforms[guestTeam].guest) {
          common++;
        }
      }
    }

    cout << common;
}
