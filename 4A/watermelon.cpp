// A. Watermelon
// - time limit per test: 1 second
// - memory limit per test: 64 megabytes
// - input: standard input
// - output: standard output
//
// One hot summer day Pete and his friend Billy decided to buy a watermelon.
// They chose the biggest and the ripest one, in their opinion.
// After that the watermelon was weighed, and the scales showed w kilos.
// They rushed home, dying of thirst, and decided to divide the berry, however they faced a hard problem.
// 
// Pete and Billy are great fans of even numbers,
// that's why they want to divide the watermelon in such a way that each of the two parts weighs even number of kilos, at the same time it is not obligatory that the parts are equal.
// The boys are extremely tired and want to start their meal as soon as possible, that's why you should help them and find out, if they can divide the watermelon in the way they want.
// For sure, each of them should get a part of positive weight.
// 
// Input
// The first (and the only) input line contains integer number w (1 ≤ w ≤ 100) — the weight of the watermelon bought by the boys.
// 
// Output
// Print YES, if the boys can divide the watermelon into two parts, each of them weighing even number of kilos; and NO in the opposite case.

#include <iostream>

int main()
{
  int w;
  std::cin >> w;

  // 10 4 6
  // w - 2 = e?
  // e + e = 2(p+q)
  // o + o = 2p + 1 + 2q + 1 = 2(p+q) + 2 = 2(p+q+1)
  if (w != 2 && w % 2 == 0 && ((w - 2) % 2 == 0)) {
        std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  return 0;
}
