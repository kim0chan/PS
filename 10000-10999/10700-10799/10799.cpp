#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int count = 0;
	int solve = 0;
	stack<int> st;

	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			st.push(1);
			count++;
		}
		else if (input[i] == ')') {
			st.pop();
			count--;
			if (input[i - 1] != '(') { solve++; continue; }
			solve += count;
		}
	}

	cout << solve;
}