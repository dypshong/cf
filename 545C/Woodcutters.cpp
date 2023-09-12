#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdint>

#define R 0
#define L 1
#define C 2

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> xs(n+1);
  std::vector<int> hs(n+1);

  for (int i = 1; i <=n; ++i) {
    std::cin >> xs[i];
    std::cin >> hs[i];
  }

  std::vector<std::vector<int64_t>> solves(n+1);
  for (int i = 1; i <= n; ++i) {
    solves[i].resize(3);
  }

  solves[1][R] = 1;
  solves[1][L] = 1;
  solves[1][C] = 0;

  for (int i = 2; i <= n; ++i) {
    if (xs[i-1] + hs[i-1] < xs[i]) {
      solves[i][R] = 1 + std::max(solves[i-1][R], std::max(solves[i-1][L], solves[i-1][C]));
      solves[i][C] = std::max(solves[i-1][R], std::max(solves[i-1][L], solves[i-1][C]));
    } else {
      solves[i][R] = 1 + std::max(solves[i-1][L], solves[i-1][C]);
      solves[i][C] = std::max(solves[i-1][L], solves[i-1][C]);
    }

    if (xs[i] - hs[i] <= xs[i-1]) {
      solves[i][L] = INT64_MIN;
    } else if (xs[i-1] + hs[i-1] < xs[i] - hs[i]) {
      solves[i][L] = 1 + std::max(solves[i-1][R], std::max(solves[i-1][L], solves[i-1][C]));
    } else {
      solves[i][L] = 1 + std::max(solves[i-1][L], solves[i-1][C]);
    }
  }

  std::cout << std::max(std::max(solves[n][L], solves[n][C]), solves[n][R]) << "\n";


  return 0;
}
