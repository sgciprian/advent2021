#include <bits/stdc++.h>
using namespace std;

struct cave {
	string name;
	bool big;
	bool visited;
	vector<string> neighbours;
};

long long track(cave c, bool vt, vector<cave> caves) {
	if (c.name == "end")
		return 1;

	long long total = 0;
	for (string n: c.neighbours)
		for (cave &t: caves)
			if (t.name == n) {
				if (t.big == true)
					total += track(t, vt, caves);
				else if (t.visited == false && t.name != "start") {
					t.visited = true;
					total += track(t, vt, caves);
					t.visited = false;
				}
				else if (t.visited == true && t.name != "start" && vt == false) // comment this for part one
					total += track(t, true, caves);
			}

	return total;
}

int main() {
	vector<cave> caves;

	string line;
	while (getline(cin, line)) {
		int dash = line.find('-');
		if (dash == -1)
			break;

		string left = line.substr(0, dash);
		string right = line.substr(dash + 1, line.length());

		bool fleft = false, fright = false;
		for (cave &c: caves) {
			if (c.name == left) {
				c.neighbours.push_back(right);
				fleft = true;
			}
			else if (c.name == right) {
				c.neighbours.push_back(left);
				fright = true;
			}
		}

		if (fleft == false)
			caves.push_back({left, left[0] >= 'A' && left[0] <= 'Z', false, {right}});

		if (fright == false)
			caves.push_back({right, right[0] >= 'A' && right[0] <= 'Z', false, {left}});
	}

	for (cave &c: caves)
		if (c.name == "start") {
			c.visited = true;
			cout << track(c, false, caves);
		}


	return 0;
}
