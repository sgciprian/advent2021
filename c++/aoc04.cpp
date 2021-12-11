#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// part two only
struct board{
	bool win;
	int val[5][5];
	bool fil[5][5];
};

vector<int> nums;
vector<board> boards;

bool mkd_row(bool val[5][5], int row) {
	for (int i = 0; i < 5; i++)
		if (val[row][i] == false)
			return false;
	return true;
}

bool mkd_col(bool val[5][5], int col) {
	for (int i = 0; i < 5; i++)
		if (val[i][col] == false)
			return false;
	return true;
}

void two() {
	string fl;

	getline(cin, fl);
	cin.get();

	istringstream cfl;
	cfl.str(fl);


	int x;
	while (cfl >> x) {
		cfl.get();
		nums.push_back(x);
	}

	while (cin >> x) {
		board b;
		b.val[0][0] = x;
		for (int i = 1; i < 25; i++) {
			cin >> x;
			b.val[i / 5][i % 5] = x;
		}
		for (int i = 0; i < 25; i++)
			b.fil[i / 5][i % 5] = false;
		b.win = false;
		boards.push_back(b);
	}

	int last = 0;
	for (int num: nums)
		for (board &b: boards) {
			if (b.win == true)
				continue;
			for (int i = 0; i < 5; i++)
				for (int  j = 0; j< 5; j++)
					if (b.val[i][j] == num) {
						b.fil[i][j] = true;
						if (mkd_row(b.fil, i) || mkd_col(b.fil, j)) {
							int sum = 0;
							for (int aa = 0; aa < 5; aa++)
								for (int bb = 0; bb < 5; bb++)
									if (b.fil[aa][bb] == false)
										sum += b.val[aa][bb];
							last = sum * num;
							b.win = true;
						}
					}
		}

	cout << last;
}

int main() {
	two();

	return 0;
}
