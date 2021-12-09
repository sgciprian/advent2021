#include <bits/stdc++.h>
using namespace std;

int dl[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};

int n, m, height[100][100];

// part one
void one() {
	int risk = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			bool lowest = true;
			for (int d = 0; d < 4; d++) {
				int ni = i + dl[d];
				int nj = j + dc[d];
				if (ni >= 0 && nj >= 0 && ni < n && nj < m && height[i][j] >= height[ni][nj])
					lowest = false;
			}
			if (lowest == true)
				risk += 1 + height[i][j];
		}
	}
	cout << risk << '\n';
}

// part two
bool hit[100][100];

int flood(int i, int j) {
	int s = 1;
	hit[i][j] = true;
	for (int d = 0; d < 4; d++) {
		int ni = i + dl[d];
		int nj = j + dc[d];
		if (ni >= 0 && nj >= 0 && ni < n && nj < m && height[ni][nj] != 9 && !hit[ni][nj])
			s += flood(ni, nj);
	}
	return s;
}

void two() {
	priority_queue<int, vector<int> > basins;

	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			bool lowest = true;
			for (int d = 0; d < 4; d++) {
				int ni = i + dl[d];
				int nj = j + dc[d];
				if (ni >= 0 && nj >= 0 && ni < n && nj < m && height[i][j] >= height[ni][nj])
					lowest = false;
			}
			if (lowest == true) {
				basins.push(flood(i, j));
			}
		}
	}


	int prod = 1;
	for (int i = 0; i < 3; i++) {
		prod *= basins.top();
		basins.pop();
	}
	cout << prod << '\n';
}

int main() {
	char c;

	int i = 0, j = 0;
	while (cin.get(c)) {
		if (c == '\n') {
			m = j;
			i++;
			j = 0;
		}
		else {
			height[i][j] = c - '0';
			j++;
		}
	}

	n = i;

	one();
	two();

	return 0;
}
