#ifndef TESTS_H
#define TESTS_H

#include "template.h"

void testInput() {
  // Read one integer, and return as tuple
  let [OneIntAsTuple] = input<int>();

  // Read one string, and return as tuple
  let [OneStringAsTuple] = input<string>();

  // Read n int and returns a vector of ints
  int n = 2;
  let VectorOfIntsN = input<int>(n);

  // Read all tokens, and return them as a joint string
  let AllTokensWithoutWhitespace = tokens::input();

  // Read 2 tokens, and return them as a joint string
  let TwoTokensWithoutWhitespace = tokens::input(2);

  // Read one single line, without leading whitespace.
  let LineWithoutLeadingWhitespace = line::input();

  // Read upto '\t' char
  let CharactersTillDelimiterWithoutLeadingWhitespace = line::input({.delim =  '\t'});

  // Read one line, and do not skip leading whitespace
  let LineWithLeadingWhitespace = line::input({ .no_trim = true });

  // Read upto '\t' char
  let CharactersTillDelimiterWithLeadingWhitespace = line::input({.delim =  '\t', .no_trim = true});

  cout << endl;

  cout << "One Int As Tuple: " << OneIntAsTuple << endl;

  cout << "One String As Tuple: " << OneStringAsTuple << endl;

  cout << "Vector Of Ints: ";
  for (auto i : VectorOfIntsN) cout << i << ' ';
  cout << endl;

  cout << "All Tokens Without Whitespace: " << AllTokensWithoutWhitespace << endl;

  cout << "Two Tokens Without Whitespace: " << TwoTokensWithoutWhitespace << endl;

  cout << "Line Without Leading Whitespace: " << LineWithoutLeadingWhitespace << endl;

  cout << "Characters Till Delimiter Without Leading Whitespace: " << CharactersTillDelimiterWithoutLeadingWhitespace << endl;

  cout << "Line With Leading Whitespace: " << LineWithLeadingWhitespace << endl;

  cout << "Characters Till Delimiter With Leading Whitespace: " << CharactersTillDelimiterWithLeadingWhitespace << endl;
}

#endif // TESTS_H
