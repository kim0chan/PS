#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	stack<int> st;
	int solve = 0;
	int temp = 1;
	bool valid = true;

	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			temp *= 2;
			st.push(1);
		}
		else if (input[i] == ')') {
			if(st.empty() || st.top() == 2) {
				valid = false;
				break;
			}
			st.pop();
			if (input[i - 1] == '(') {
				solve += temp;
			}
			temp /= 2;
		}
		else if (input[i] == '[') {
			temp *= 3;
			st.push(2);
		}
		else if (input[i] == ']') {
			if (st.empty() || st.top() == 1) {
				valid = false;
				break;
			}
			st.pop();
			if (input[i - 1] == '[') {
				solve += temp;
			}
			temp /= 3;
		}
	}

	if (valid && st.empty()) {
		cout << solve;
	}
	else {
		cout << 0;
	}
}