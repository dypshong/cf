#include <iostream>
#include <vector>

int main()
{
  int n, m;
  std::cin >> n;
  std::cin >> m;

  std::vector<int> nnames(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> nnames[i];
  }

  int accum = 0;
  for (int i = 0; i < n; ++i) {
    int turn = 0;

    accum += nnames[i];
    if (accum >= m) {
      turn = accum / m;
      accum = accum % m;
    }
    std::cout << turn << " ";
  }
  std::cout << "\n";
  return 0;
}
