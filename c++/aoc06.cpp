#include <iostream>
#include <unordered_map>
using namespace std;

// both parts in one
int main() {
	unordered_map<int, long long> prev, curr;
	char c;

	c = cin.get();
	while (c >= '0' && c <= '9') {
		prev[c - '0']++;
		c = cin.get();
		if (c == ',')
			c = cin.get();
	}

	for (int d = 0; d < 256; d++) {
		curr[6] += prev[0];
		curr[8] += prev[0];

		for (int k = 1; k <= 8; k++)
			curr[k - 1] += prev[k];

		prev = curr;
		curr.clear();
	}

	long long sum = 0;
	for (int k = 0; k <= 8; k++)
		sum += prev[k];

	cout << sum;

  return 0;
}
