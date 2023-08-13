#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string num;
	std::cin >> num;

	std::vector<int> numbers(num.length());
	for (int i = 0; i < num.length(); ++i) {
		numbers[i] = num[i] - '0';
	}

	for (int i = 0; i < num.length(); ++i) {
		int val_i = numbers[i];
		if (val_i % 8 == 0) {
			std::cout << "YES\n";
			std::cout << val_i << "\n";
			return 0;
		}

		for (int j = i+1; j < num.length(); ++j) {
			int val_j = numbers[j];
			int val = val_i * 10 + val_j;
			if (val % 8 == 0) {
				std::cout << "YES\n";
				std::cout << val << "\n";
				return 0;
			}
			for (int k = j+1; k < num.length(); ++k) {
				int val_k = numbers[k];
				int val = val_i * 100 + val_j * 10 + val_k;
				if (val % 8 == 0) {
					std::cout << "YES\n";
					std::cout << val << "\n";
					return 0;
				}
			}
		}
	}

	std::cout << "NO\n";

	return 0;
}
