#include <iostream>
#include <vector>
#include <map>
#include <cstdint>

int main()
{
  int n;
  std::cin >> n;

  std::vector<int64_t> potions(n+1);
  std::vector<int64_t> acc(n+1);
  std::vector<std::vector<int>> H(n+1);
  std::vector<int> solves(n+1);

  for (int i = 1; i <= n; ++i) {
    std::cin >> potions[i];
    H[i].resize(n+1);
  }

  acc[0] = 0;
  for (int i = 1; i <= n; ++i) {
    acc[i] = acc[i-1] + potions[i];
  }

  for (int i = n; i >= 1; --i) {
    H[i][n] = (((acc[n] - acc[i-1]) >= 0) ? 1 : 0);
  }

  for (int j = n-1; j >= 1; --j) {
    for (int i = j; i >= 1; --i) {
      H[i][j] = (acc[j] - acc[i-1] >= 0) ? std::max(1 + H[i][j+1], H[j+1][j+1]) : H[j+1][j+1];
    }
  }

  solves[n] = H[n][n];
  for (int i = n-1; i >= 1; --i) {
    solves[i] = (potions[i] >= 0 ? std::max(1+H[i][i+1], solves[i+1]) : solves[i+1]);
  }

  for (int i = 1; i <= n; ++i)  {
    for (int j = 1; j <= n; ++j) {
      std::cout << H[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << solves[1] << "\n";
  return 0;
}
