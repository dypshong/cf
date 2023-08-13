#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string seq;
	std::cin >> seq;

	std::vector<int> containsAB(seq.length());
	std::vector<int> containsBA(seq.length());

	for (int i = 0; i < seq.length(); ++i) {
		containsAB[i] = 0;
		containsBA[i] = 0;
	}

	for (int i = 1; i < seq.length(); ++i) {
		if ((containsAB[i-1] == 1)
				|| (seq[i-1] == 'A' && seq[i] == 'B')) {
			containsAB[i] = 1;
		}

		if ((containsBA[i-1] == 1)
				|| (seq[i-1] == 'B' && seq[i] == 'A')) {
			containsBA[i] = 1;
		}
	}

	for (int i = seq.length()-2; i >= 2; --i) {
		if (seq[i] == 'A' && seq[i+1] == 'B') {
			if (containsBA[i-1]) {
				std::cout << "YES\n";
				return 0;
			}
		} else if (seq[i] == 'B' && seq[i+1] == 'A') {
			if (containsAB[i-1]) {
				std::cout << "YES\n";
				return 0;
			}
		} 
	}
	std::cout << "NO\n";

	return 0;
}
