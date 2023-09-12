#include <iostream>
#include <string>

int main()
{
  int n;
  std::cin >> n;

  std::vector<std::string> strings(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> strings[i];
    std::string &s = strings[i];

    if (s.length() > 10) {
      strings[i] = std::string(1, s[0]) + std::to_string(s.length()-2) + std::string(1, s[s.length()-1]);
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << strings[i] << "\n";
  }
  return 0;
}
