#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int sum = 0;
	int N;
	cin >> N;

	while (N--) {
		int input;
		cin >> input;
		pq.push(input);
	}

	while (pq.size() != 1) {
		int a = pq.top();	pq.pop();
		int b = pq.top();	pq.pop();

		sum += a + b;
		pq.push(a + b);
	}

	cout << sum << '\n';
}