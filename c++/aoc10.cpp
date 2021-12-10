#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	long long score_one = 0;
	vector<long long> scores;

	while (getline(cin, line)) {
		stack<char> s;
		bool incomplete = true;

		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '(' || line[i] == '[' || line[i]=='{' || line[i]=='<')
				s.push(line[i]);
			else {
				if (s.top() != '(' && line[i] == ')') {
					incomplete = false;
					score_one += 3;
					break;
				}
				else if (s.top() != '[' && line[i] == ']') {
					incomplete = false;
					score_one += 57;
					break;
				}
				else if (s.top() != '{' && line[i] == '}') {
					incomplete = false;
					score_one += 1197;
					break;
				}
				else if (s.top() != '<' && line[i] == '>') {
					incomplete = false;
					score_one += 25137;
					break;
				}
				s.pop();
			}
		}

		if (incomplete) {
			long long score = 0;
			while (!s.empty()) {
				score *= 5;
				if (s.top() == '(')
					score += 1;
				else if (s.top() == '[')
					score += 2;
				else if (s.top() == '{')
					score += 3;
				else if (s.top() == '<')
					score += 4;
				s.pop();
			}
			scores.push_back(score);
		}
	}

	cout << score_one << '\n';

	sort(scores.begin(), scores.end());
	cout << scores[scores.size() / 2] << '\n';

	return 0;
}
