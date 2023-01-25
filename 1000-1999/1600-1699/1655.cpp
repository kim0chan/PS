#include <bits/stdc++.h>

//#define MIN(a, b)	a<b ? a:b

using namespace std;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		if (maxpq.size() == minpq.size()) {
			maxpq.push(input);
		}
		else {
			minpq.push(input);
		}

		if (!minpq.empty() && (maxpq.top() > minpq.top())) {
			int a, b;
			a = maxpq.top();	maxpq.pop();
			b = minpq.top();	minpq.pop();

			maxpq.push(b);
			minpq.push(a);
		}

		cout << maxpq.top() << '\n';
	}
}