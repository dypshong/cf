#include <iostream>

int main()
{
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t) {
    int n, a, b;
    std::cin >> n >> a >> b;


    if (a == 1) {
      if ((n - 1) % b == 0) {
        std::cout << "Yes\n";
      } else {
        std::cout << "No\n";
      }
      continue;
    }

    if (b == 1) {
      std::cout << "Yes\n";
      continue;
    }

    while (n > 1) {
      std::cout << n << "\n";

      while (n > 1 && (n % a) % b != 0) {
        n -= b;
      }

      while (n > 1 && n % a == 0) {
        n /= a;
      }
    }

    if (n == 1) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
  return 0;
}
