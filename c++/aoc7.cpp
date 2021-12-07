#include <iostream>
using namespace std;

int main() {
	int x, n, v[2000];

	while (cin >> x) {
		v[n++] = x;
		char c = cin.get();
	}

	int d = 99999999;
	for (int p = 0; p < 2000; p++) {
		int c = 0;
		for (int i = 0; i < n; i++)
			c += abs(v[i] - p) * (abs(v[i] - p) + 1) / 2; // add just the abs for part one
		d = min(d, c);
	}

	cout << d;

	return 0;
}
