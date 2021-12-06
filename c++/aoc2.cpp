#include <iostream>
#include <string>
using namespace std;

// part one
void one() {
	string dir;
	int x;

	int h = 0;
	int d = 0;

	while (cin >> dir >> x) {
		if (dir[0] == 'f')
			h += x;
		else if (dir[0] == 'd')
			d += x;
		else
			d -= x;
	}

	cout << d * h;
}

// part two
void two() {
	string dir;
	int x;

	int a = 0;
	int h = 0;
	int d = 0;

	while (cin >> dir >> x) {
		if (dir[0] == 'f') {
			h += x;
			d += a * x;
		}
		else if (dir[0] == 'd')
			a += x;
		else
			a -= x;
	}

	cout << d * h;
}

int main() {
	one();
	two();

	return 0;
}
