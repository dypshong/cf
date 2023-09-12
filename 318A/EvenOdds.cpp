#include <iostream>
#include <cstdint>

int main()
{
  uint64_t n, k;

  std::cin >> n;
  std::cin >> k;

  uint64_t num_odds = ((n+1) / 2);
  uint64_t num_evens = (n / 2);

  if (k <= num_odds) {
    std::cout << (2 * k - 1) << "\n";
  } else {
    k = k - num_odds;
    std::cout << (2 * k) << "\n";
  }
  return 0;
}
