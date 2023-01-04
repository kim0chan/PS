#include <iostream>
#include <stack>

using namespace std;

int main() {
	int N;
	int num, sum;

	stack<int> st;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (!num) {
			if (st.size()) {
				st.pop();
			}
		}
		else {
			st.push(num);
		}
	}

	sum = 0;
	while (st.size()) {
		sum += st.top();
		st.pop();
	}

	cout << sum << '\n';

	return 0;
}