#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;

  int m;
  std::cin >> m;
  std::vector<int> ls(m);
  std::vector<int> rs(m);
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> ls[i];
    std::cin >> rs[i];
  }
  for (int i = 0; i < m; ++i) {
    int l = ls[i];
    int r = rs[i];
  }
  return 0;
}
