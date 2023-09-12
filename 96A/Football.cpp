#include <iostream>
#include <string>

int main()
{
  std::string bitstring;
  std::cin >> bitstring;


  int i = 1;
  int long_length = 1;
  char bit_at_i = bitstring[0];
  while (i < bitstring.length()) {
    if (bitstring[i] == bit_at_i) {
      ++long_length;
    } else {
      long_length = 1;
      bit_at_i = bitstring[i];
    }

    if (long_length == 7) {
      std::cout << "YES\n";
      return 0;
    }
    ++i;
  }
  
  std::cout << "NO\n";

  return 0;
}
