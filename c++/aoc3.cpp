#include <iostream>
#include <vector>
using namespace std;

// part one
int f[12];

void one() {
	long long x;
	int n = 0;

	while (cin >> x) {
		n++;
		int k = 0;
		while (x > 0) {
			f[k] += x % 10;
			x /= 10;
			k++;
		}
	}

	long long gamma = 0, epsilon = 0;
	long long pow = 1;
	for (int k = 0; k < 12; k++) {
		gamma += pow * (2*f[k] >= n);
		epsilon += pow * (2*f[k] < n);
		pow *= 2;
	}

	cout << gamma * epsilon;
}

// part two
vector<long long> v, w;

void two() {
	long long x;
	while (cin >> x) v.push_back(x);
	w = vector<long long>(v);

	long long pow = 1;
	for (int i = 1; i < 12; i++)
		pow *= 10;

	while (v.size() > 1) {
		int f = 0;

		for (int i = 0; i < v.size(); i++)
			if ((v[i] / pow) % 10 == 1)
				f++;

		if (2*f >= v.size()) {
			for (int i = 0; i < v.size(); i++)
				if ((v[i] / pow) % 10 == 0) {
					v.erase(v.begin() + i);
					i--;
				}
		}	else
			for (int i = 0; i < v.size(); i++)
				if ((v[i] / pow) % 10 == 1) {
					v.erase(v.begin() + i);
					i--;
				}

		pow /= 10;
	}

	pow = 1;
	for (int i = 1; i < 12; i++)
		pow *= 10;

	while (w.size() > 1) {
		int f = 0;
		for (int i = 0; i < w.size(); i++)
			if ((w[i] / pow) % 10 == 1)
				f++;

		if (2*f >= w.size()) {
			for (int i = 0; i < w.size(); i++)
				if ((w[i] / pow) % 10 == 1) {
					w.erase(w.begin() + i);
					i--;
				}
		} else
			for (int i = 0; i < w.size(); i++)
				if ((w[i] / pow) % 10 == 0) {
					w.erase(w.begin() + i);
					i--;
				}

		pow /= 10;
	}

	long long oxy = 0;

	pow = 1;
	while (v[0] > 0) {
		oxy = oxy + (v[0] % 10) * pow;
		v[0] /= 10;
		pow *= 2;
	}

	long long co2 = 0;
	pow = 1;
	while (w[0] > 0) {
		co2 = co2 + (w[0] % 10) * pow;
		w[0] /= 10;
		pow *= 2;
	}

	cout << oxy *  co2 ;
}

int main() {
	one();
	two();

	return 0;
}
