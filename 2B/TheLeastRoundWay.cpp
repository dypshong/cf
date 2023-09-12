#include <iostream>
#include <vector>
#include <utility>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> mat(n+1);
  std::vector<std::vector<int>> fac2(n+1);
  std::vector<std::vector<int>> fac5(n+1);
  std::vector<std::vector<int>> fac10(n+1);
  std::vector<std::vector<std::pair<int, int>>> solve2(n+1);
  std::vector<std::vector<std::pair<int, int>>> solve5(n+1);
  std::vector<std::vector<char>> dir(n+1);

  for (int i = 1; i <= n; ++i) {
    mat[i].resize(n+1);
    fac2[i].resize(n+1);
    fac5[i].resize(n+1);
    fac10[i].resize(n+1);
    solve2[i].resize(n+1);
    solve5[i].resize(n+1);
    dir[i].resize(n+1);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> mat[i][j];
      int val = mat[i][j];
      int n2 = 0;
      int n5 = 0;
      int n10 = 0;

      // 10 doesn't necessary
      while (val % 10 == 0) {
        ++n10;
        val /= 10;
      }

      while (val % 2 == 0) {
        ++n2;
        val /= 2;
      }
      while (val % 5 == 0) {
        ++n5;
        val /= 5;
      }
      fac2[i][j] = n2;
      fac5[i][j] = n5;
      fac10[i][j] = n10;
    }
  }

  solve2[n][n] = std::make_pair(fac2[n][n], fac10[n][n]);
  solve5[n][n] = std::make_pair(fac5[n][n], fac10[n][n]);

  for (int j = n-1; j >= 1; --j) {
    if (fac2[j][n] != 0) {
      solve2[j][n] = solve2[j+1][n];
      solve5[j][n] = 
        fac5[j][n]
    } else {
      solve5[j][n] = solve5[j+1][n];
    }
    solve2[j][n] = std::make_pair(fac2[j][n] + solve2[j+1][n].first, solve2[j+1][n].second);
    solve2[j][n] = std::make_pair(
        std::max(fac2[j][n], solve5[j+1][n].first) - std::min(fac2[j][n], solve5[j+1][n].first),
        std::min(fac2[j][n], solve5[j+1][n].first) + solve5[j+1][n].second);
  }

  for (int i = n-1; i >= 1; --i) {
  }

  return 0;
}
