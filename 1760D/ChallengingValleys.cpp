#include <iostream>
#include <vector>

int main()
{
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int j = 0; j < n; ++j) {
			std::cin >> a[j];
		}

		int numValleys = 0;
		int l, r;
		l = 0;
		r = 0;

		// 3 2 2 1 2 2 3
		while (l < n) {
			r = l;
			while (r < n-1 && a[r+1] == a[l]) {
				++r;
			}

			if ((l == 0 || a[l-1] > a[l])
					&& (r == n-1 || a[r] < a[r+1])) {
				numValleys++;
			}
			l = r+1;
		}

		if (numValleys == 1) {
			std::cout << "YES" << "\n";
		} else {
			std::cout << "NO" << "\n";
		}
	}
	return 0;
}
