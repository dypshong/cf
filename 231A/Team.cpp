#include <iostream>

int main()
{
  int sum = 0;
  int n;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int n0, n1, n2;
    std::cin >> n0;
    std::cin >> n1;
    std::cin >> n2;

    if ((n0 + n1 + n2) >= 2)
      ++sum;
  }
  std::cout << sum << "\n";
  return 0;
}
