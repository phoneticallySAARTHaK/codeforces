#include "template.h"

fn getFaces(sv shape) {
  if (shape == "Tetrahedron")
    return 4;

  if (shape == "Cube")
    return 6;

  if (shape == "Octahedron")
    return 8;

  if (shape == "Dodecahedron")
    return 12;

  if (shape == "Icosahedron")
    return 20;

  assert(false && "not a shape");
  return 0;
}

fn solve() -> void {
  discard<int>();
  int faces{};
  for_each(isr<string>(),
           [&faces](auto &shape) mut { faces += getFaces(shape); });
  cout << faces;
}
