#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
      std::cout << "YES\n";
      return 0;
    }
  }

  std::cout << "NO\n";
  return 0;
}
