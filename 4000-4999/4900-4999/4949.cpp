#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	string input;

	while (true) {
		stack<int> st;
		bool valid = 1;
		getline(cin, input);
		if (input == ".") { break; }
		else {
			for (auto t : input) {
				if (t == '(') {
					st.push(1);
				}
				else if (t == '[') {
					st.push(2);
				}
				else if (t == ')') {
					if (!st.empty()) {
						if (st.top() == 1) {
							st.pop();
						}
						else {
							valid = false;
							break;
						}
					}
					else {
						valid = false;
						break;
					}
				}
				else if (t == ']') {
					if (!st.empty()) {
						if (st.top() == 2) {
							st.pop();
						}
						else {
							valid = false;
							break;
						}
					}
					else {
						valid = false;
						break;
					}
				}
			}
			if (valid && st.empty()) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}
}