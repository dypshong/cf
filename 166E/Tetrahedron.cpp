#include <iostream>
#include <cstdint>

int main()
{
  int64_t a, b, c, d;

  int n;
  std::cin >> n;

  a = 0;
  b = 0;
  c = 0;
  d = 1;
  for (int i = 0; i < n; ++i) {
    int64_t new_a = (b + c + d) % 1000000007;
    int64_t new_b = (a + c + d) % 1000000007;
    int64_t new_c = (a + b + d) % 1000000007;
    int64_t new_d = (a + b + c) % 1000000007;

    a = new_a;
    b = new_b;
    c = new_c;
    d = new_d;
  }

  std::cout << d << "\n";
  return 0;
}
