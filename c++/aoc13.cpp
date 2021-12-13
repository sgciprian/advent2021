#include <bits/stdc++.h>
using namespace std;

bool point[3000][3000];
void see(int n, int m, vector<pair<int,int>> points) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			point[i][j] = false;
	}
	for(pair<int,int> p: points)
		point[p.second][p.first]=true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << (point[i][j] ? '#' : '.');
		cout << '\n';
	}
}

struct {
		bool operator()(pair<int,int> a, pair<int,int> b) const {
			if (a.first == b.first)
				return a.second < b.second;
			return a.first < b.first;
		}
} pairCompare;

int main() {
	vector<pair<int,int>> points;
	string line;

	int n = 0, m = 0;
	while (getline(cin, line)) {
		if (line.length() == 0)
			break;

		stringstream ss(line);
		int x, y;
		ss >> x;
		ss.get();
		ss >> y;
		ss.get();

		points.push_back({x, y});
		n = max(n, x);
		m = max(m, y);
	}
	n++; m++;

	cin.get();

	while (getline(cin, line)) {
		stringstream ss(line);

		ss.ignore(12);
		int x;
		ss >> x;

		if (line[10] == 'x') {
			int nn = max(x, n - x - 1);
			for (pair<int,int> &p: points)
					p.first = nn - abs(p.first - x);
			n = nn;
		}
		else {
			int mm = max(x, m - x - 1);
			for (pair<int,int> &p: points)
				p.second = mm - abs(p.second - x);
			m = mm;
		}

		sort( points.begin(), points.end(), pairCompare );
		points.erase( unique( points.begin(), points.end() ), points.end() );
		cout << points.size() << '\n';

		cin.get();
	}

	see(n, m, points);

	return 0;
}
