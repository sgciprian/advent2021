#include <iostream>
using namespace std;

constexpr bool part_one = false;

int h[10][10];

long long flash(int i, int j) {
	long long flashes = 1;

	for (int l = -1; l <= 1; l++)
		for (int c = -1; c <= 1; c++) {
			int ni = i + l;
			int nj = j + c;
			if (ni >= 0 && nj >= 0 && ni < 10 && nj < 10 && h[ni][nj] != -1)
				h[ni][nj]++;
		}

	h[i][j] = -1;

	for (int l = -1; l <= 1; l++)
		for (int c = -1; c <= 1; c++) {
			int ni = i + l;
			int nj = j + c;
			if (ni >= 0 && nj >= 0 && ni < 10 && nj < 10 && h[ni][nj] != -1 && h[ni][nj] >= 10)
				flashes += flash(ni, nj);
		}

	return flashes;
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			h[i][j] = cin.get() - '0';
		cin.get();
	}

	long long flashes = 0;

	for (int step = 1; part_one ? (step <= 100) : true; step++) {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				h[i][j]++;

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if (h[i][j] == 10) {
					int cnt = flash(i, j);
					if (!part_one && cnt == 100) {
						cout << step << '\n';
						return 0;
					}
					flashes += cnt;
				}

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if (h[i][j] == -1)
					h[i][j] = 0;
	}

	cout << flashes;

	return 0;
}
