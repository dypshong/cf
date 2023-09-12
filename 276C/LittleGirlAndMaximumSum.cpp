#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

int main()
{
  int n, q;

  std::cin >> n >> q;

  std::vector<int> arr(n+1);
  std::vector<std::pair<int, int>> queries(q+1);
  std::vector<int> count(n+1);

  for (int i = 1; i <= n; ++i) {
    std::cin >> arr[i];
  }

  for (int j = 1; j <= q; ++j) {
    std::cin >> queries[j].first >> queries[j].second;
  }

  for (int i = 1; i <= n; ++i) {
    count[i] = 0;
  }

  // 1 2
  // 1   3
  // 1     4
  //   2 3
  //   2       6
  //
  //
  // 3 2 0 0 0 0 start
  // 0 1 2 1 0 1 end
  // 
  // 0
  // 0 0 0 0 0 0
  // 3
  // 3 0 0 0 0 0
  // (3 + 2) - 1 = 4
  // 3 5 0 0 1 1
  // 4 - 2 = 2
  // 3 5 4 0 1 1
  // 2
  // 3 5 4 2 1 1
  //
  // 2
  // 0 0 0 2 1 1
  //
  // 3 5 4 3 1 1
  // 1 1
  // 1   1
  // 1     1
  //
  std::sort(queries.begin(), queries.end());
  

  std::vector<int> starts(n+1);
  std::vector<int> ends(n+1);
  for (int i = 1; i <= n; ++i) {
    starts[i] = 0;
    ends[i] = 0;
  }
  for (int j = 1; j <= q; ++j) {
    ++starts[queries[j].first];
    ++ends[queries[j].second];
  }

  int carry = 0;
  for (int i = 1; i <= n; ++i) {
    carry += starts[i];
    count[i] += carry;
    carry -= ends[i];
  }


  count[0] = INT_MIN;
  std::vector<int> idx(n+1);
  for (int i = 1; i <= n; ++i) {
    idx[i] = i;
  }
  std::sort(idx.begin(), idx.end(), [&](auto i, auto j) {
      return (count[i] < count[j]) || ((count[i] == count[j]) ? arr[i] < arr[j] : false);
      });
  std::sort(arr.begin(), arr.end());

  std::vector<int> new_arr(n+1);
  for (int i = 1; i <= n; ++i) {
    new_arr[idx[i]] = arr[i];
  }

  std::vector<int64_t> acc(n+1);
  acc[0] = 0;
  for (int i = 1; i <= n; ++i) {
    acc[i] = acc[i-1] + new_arr[i];
  }

  int64_t sum = 0;
  for (int j = 1; j <= q; ++j) {
    sum += acc[queries[j].second] - acc[queries[j].first-1];
  }
  std::cout << sum << "\n";
  
  return 0;
}
