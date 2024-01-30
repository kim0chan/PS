#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N;
	string input;
	int num;

	cin >> N;
	stack<int> st;

	for (int i = 0; i < N; i++) {
		cin >> input;
	
		if (input == "push") {
			cin >> num;
			st.push(num);
		}
		else if (input == "top") {
			if (st.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << st.top() << '\n';
			}
		}
		else if (input == "empty") {
			cout << st.empty() << '\n';
		}
		else if (input == "size") {
			cout << st.size() << '\n';
		}
		else if (input == "pop") {
			if (st.empty()) { num = -1; }
			else {
				num = st.top();
				st.pop();
			}
			cout << num << '\n';
		}
		else {
			cout << "a bug occurred" << '\n';
		}
	}

	return 0;
}