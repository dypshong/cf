#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;

  for (int i = 0; i < s.length(); ++i) {
    if (   s[i] == 'A'
        || s[i] == 'O'
        || s[i] == 'Y'
        || s[i] == 'E'
        || s[i] == 'U'
        || s[i] == 'I'
        || s[i] == 'a'
        || s[i] == 'o'
        || s[i] == 'y'
        || s[i] == 'e'
        || s[i] == 'u'
        || s[i] == 'i') {
      /* Do nothing */
    } else {
      std::cout << ".";
      if ('A' <= s[i] && s[i] <= 'Z')
        s[i] = 'a' + (s[i] - 'A');
      std::cout << s[i];
    }
  }
  std::cout << "\n";
  return 0;
}
