#include <iostream>
#include <algorithm>

int main()
{
  int n;

  std::cin >> n;
  std::vector<int> coins(n);

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> coins[i];
    sum += coins[i];
  }

  std::sort(coins.begin(), coins.end());
  
  int take = 0;
  for (int i = n-1; i >= 0; --i) {
    take += coins[i];
    if (take > (sum - take)) {
      std::cout << (n - i) << "\n";
      break;
    }
  }

  return 0;
}
