#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>


int main()
{
	int n, d;
	std::cin >> n >> d;

	std::vector<uint64_t> M(n);
	std::vector<uint64_t> S(n);
	std::vector<uint64_t> ACC(n+1);
	std::vector<uint64_t> TMP(n);
	std::vector<uint64_t> IDX(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> M[i] >> S[i];
		IDX[i] = i;
	}

	std::sort(IDX.begin(), IDX.end(), [&](auto i, auto j) {
			return M[i] < M[j] || (M[i] == M[j] && S[i] < S[j]);
			});

	for (int i = 0; i < n; ++i) {
		TMP[i] = M[i];
	}
	for (int i = 0; i < n; ++i) {
		M[i] = TMP[IDX[i]];
	}

	for (int i = 0; i < n; ++i) {
		TMP[i] = S[i];
	}
	for (int i = 0; i < n; ++i) {
		S[i] = TMP[IDX[i]];
	}

	ACC[0] = 0;
	for (int i = 1; i <= n; ++i) {
		ACC[i] = ACC[i-1] + S[i-1];
	}

	uint64_t max = 0;
	int l, r;
	l = r = 0;
	for (l = 0; l < n; ++l) {
		while (r < n && M[r] - M[l] < d) {
			++r;
		}
		uint64_t sum = ACC[r] - ACC[l];
		max = std::max(max, sum);
	}

	std::cout << max << "\n";

	return 0;
}
