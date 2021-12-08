#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void one() {
	string fl;
	int occ = 0;

	while (getline(cin, fl)) {
		cin.get();

		istringstream cfl;
		cfl.str(fl);

		string pat;
		for (int i = 0; i < 10; i++)
			cfl >> pat;

		cfl >> pat;

		for (int i = 0; i < 4; i++) {
			cfl >> pat;
			if (pat.size() == 2 || pat.size() == 4 || pat.size() == 3 || pat.size() == 7)
				occ++;
		}
	}

	cout << occ;
}

void two() {
	string fl;

	int sum = 0;

	while (getline(cin, fl)) {
		int freq[7], freq1[7], freq4[7], freq7[7];
		for (int i = 0; i < 7; i++) {
			freq[i] = 0;
			freq1[i] = 0;
			freq4[i] = 0;
			freq7[i] = 0;
		}

		istringstream cfl;
		cfl.str(fl);

		string pat;
		for (int i = 0; i < 10; i++) {
			cfl >> pat;
			for (int j = 0; j < pat.size(); j++) {
				freq[pat[j] - 'a']++;
				if (pat.size() == 2)
					freq1[pat[j] - 'a']++;
				if (pat.size() == 4)
					freq4[pat[j] - 'a']++;
				if (pat.size() == 3)
					freq7[pat[j] - 'a']++;
			}
		}

		int val[7];
		for (int i = 0; i < 7; i++) {
			if (freq[i] == 6)
				val[i] = 1; // place of b
			else if (freq[i] == 4)
				val[i] = 4; // place of e
			else if (freq[i] == 9)
				val[i] = 5; // place of f
			else if (freq1[i] == 1) // other segment of 1
				val[i] = 2; // place of c
			else if (freq4[i] == 1) // remaining segment of 4
				val[i] = 3; // place of d
			else if (freq7[i] == 1) // remaining segment of 7
				val[i] = 0; // place of a
			else
				val[i] = 6; // place of g
		}

		cfl >> pat; // pipe
		if (pat.size() == 0)
			break; // empty line

		int cr = 0;
		for (int i = 0; i < 4; i++) {
			cfl >> pat;

			if (pat.size() == 2)
				cr = cr * 10 + 1;
			else if (pat.size() == 3)
				cr = cr * 10 + 7;
			else if (pat.size() == 4)
				cr = cr * 10 + 4;
			else if (pat.size() == 7)
				cr = cr * 10 + 8;
			else if (pat.size() == 5) {
				bool ok = false;
				for (int i = 0; i < 5; i++) {
					if (val[pat[i] - 'a'] == 1) {
						cr = cr * 10 + 5; // only one with place of b
						ok = true;
						break;
					}
					if (val[pat[i] - 'a'] == 4) {
						cr = cr * 10 + 2; // only one with place of e
						ok = true;
						break;
					}
				}
				if (!ok)
					cr = cr * 10 + 3; // only this is left
			}
			else {
				bool okc = false;
				bool oke = false;
				for (int i = 0; i < 6; i++) {
					if (val[pat[i] - 'a'] == 2)
						okc = true;
					if (val[pat[i] - 'a'] == 4)
						oke = true;
				}
				if (oke && okc)
					cr = cr * 10 + 0; // has both e and c
				else if (oke)
					cr = cr * 10 + 6; // only has e
				else
					cr = cr * 10 + 9; // only has c
			}
		}
		sum += cr;
		cout << cr << '\n';
	}

	cout << sum;
}

int main() {
	two();

	return 0;
}
