#include <bits/stdc++.h>
using namespace std;

int N, input;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> input;
		pq.push(input);
		if (N < (int)pq.size())	pq.pop();
	}

	cout << pq.top() << '\n';
}