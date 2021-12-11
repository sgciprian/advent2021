#include <iostream>
#include <queue>
using namespace std;

// part one
void one() {
	int x, p, k = 0;

	cin >> p;
	while (cin >> x) {
		k += x > p;
		p = x;
	}

	cout << k << '\n';
}


// part two
void two() {
	queue<int> sw;
	int x, k = 0;

	while (cin >> x) {
		sw.push(x);

		if (sw.size() == 4) {
			k += sw.back() > sw.front();
			sw.pop();
		}
	}

	cout << k << '\n';
}

int main() {
	one();
	two();

	return 0;
}
