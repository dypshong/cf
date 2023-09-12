#include <iostream>
#include <cstdint>

int main()
{
  uint64_t n, m, a;
  std::cin >> n;
  std::cin >> m;
  std::cin >> a;

  uint64_t h = ((n + a - 1) / a);
  uint64_t w = ((m + a - 1) / a);
  std::cout << h * w << "\n";

  return 0;
}
