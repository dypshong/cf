#include <iostream>
#include <vector>

int main()
{
  std::string seq;
  std::cin >> seq;

  std::vector<int> legals(seq.length()+1);

  int max_len = -1;
  int count = 0;
  int len = 0;
  int stack = 0;

  for (int i = 0; i < seq.length(); ++i) {
    if (seq[i] == '(') {
      ++stack;
    } else {
      --stack;
      if (stack < 0) {
        if (max_len < len) {
          max_len = len;
          count = 1;
        } else if (max_len == len) {
          ++count;
        }
        std::cout << "COUNTING NEG " << i << ": " << max_len << " " << count << "\n";
        stack = 0;
        len = 0;
      } else {
        len += 2;
      }
    }
  }

  if (max_len < len) {
    max_len = len;
    count = 1;
  } else if (max_len == len) {
    ++count;
  } 


  if (max_len == 0)
    count = 1;

  std::cout << max_len << " " << count << "\n";
  return 0;
}
