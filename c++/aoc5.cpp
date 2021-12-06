#include <iostream>
using namespace std;

// both parts in one, ish
int f[10000][10000];

int main() {
	int x1, y1, x2, y2;

	while (cin >> x1) {
		cin.get();
		cin >> y1; cin.get(); cin.get(); cin.get(); cin.get();
		cin >> x2; cin.get();
		cin >> y2;

		int dx;
		if (x1 == x2)
			dx = 0;
		else
			dx = (x1 > x2) ? (-1) : 1;

		int dy;
		if (y1 == y2)
			dy = 0;
		else
			dy = (y1 > y2) ? (-1) : 1;

		f[x1][y1]++;
		while (x1 != x2 || y1 != y2) {
			x1 += dx;
			y1 += dy;
			f[x1][y1]++;
		}
	}

	int k = 0;
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			if (f[i][j] > 1)
				k++;

	cout << k;

	return 0;
}
