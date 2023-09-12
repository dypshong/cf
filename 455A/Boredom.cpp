#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>



int main()
{
  int n;
  std::cin >> n;

  std::vector<int> as(n+2);
  for (int i = 1; i <= n; ++i) {
    std::cin >> as[i];
  }
  as[n+1] = 0;

  std::sort(as.begin()+1, as.begin()+n+1);

  std::vector<int> counts;
  std::vector<int> unique_values;
  int i = 1;
  while (i <= n) {
    int l = i;
    int val = as[i];
    while (i <= n && as[i] == val) {
      ++i;
    }
    unique_values.push_back(val);
    counts.push_back(i - l);
  }

  std::vector<uint64_t> solves(unique_values.size() + 2);
  int l = unique_values.size()-1;
  solves[l + 2] = 0;
  solves[l + 1] = 0;
  unique_values.push_back(0);
  while (l >= 0) {
    uint64_t gain = static_cast<uint64_t>(unique_values[l]) * counts[l];
    if ((unique_values[l] + 1) == unique_values[l+1]) {
      solves[l] = std::max(gain + solves[l+2], solves[l+1]);
    } else {
      solves[l] = gain + solves[l+1];
    }
    --l;
  }

  std::cout << solves[0] << "\n";

  return 0;
}
