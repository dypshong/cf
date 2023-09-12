#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  for (int i = 0; i < n; ++i) {
    int number = numbers[i];

    int n3 = 0;
    int n6 = 0;

    while (number > 1) {
      if (number % 6 == 0) {
        ++n6;
        number = number / 6;
      } else if (number % 3 == 0) {
        ++n3;
        number = number / 3;
      } else {
        break;
      }
    }

    if (number != 1) {
      std::cout << -1 << "\n";
    } else {
      std::cout << 2 * n3 + n6 << "\n";
    }
  }
  return 0;
}
