#include <iostream>
#include <cstdint>

int main()
{
  int n;
  uint64_t k;
  std::cin >> n;
  std::cin >> k;
  std::vector<int> as(n+1);
  std::vector<int> perm(n+1);
  std::vector<int> numbers(n+1);
  std::vector<std::vector<int>*> cycles(n+1);

  for (int i = 1; i <= n; ++i) {
    std::cin >> as[i];
    perm[as[i]] = i;
    cycles[i] = nullptr;
    numbers[i] = 0;
  }

  for (int i = 1; i <= n; ++i) {
    int j = i;

    if (cycles[j] == nullptr) {
      std::vector<int> *cycle_ids = new std::vector<int>();

      cycles[j] = cycle_ids;
      cycle_ids->push_back(j);
      int start = j;
      j = perm[j];
      while (j != start) {
        cycle_ids->push_back(j);
        cycles[j] = cycle_ids;
        j = perm[j];
      }
    }
  }

  for (int i = 1; i <= n; ++i) {

    if (numbers[i] == 0) {
      std::vector<int> &cycle = *cycles[i];
      int cycle_length = cycle.size();

      for (int j = 0; j < cycle_length; ++j) {
        numbers[cycle[j]] = cycle[(j + k) % cycle_length];
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << "\n";

  return 0;
}
