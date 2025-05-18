#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> qu;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int ans;

	cin >> N;
	for (int i = 1; i <= N; i++)	qu.push(i);

	while (qu.size() > 1) {
		qu.pop();
		qu.push(qu.front());	qu.pop();
	}

	cout << qu.front() << '\n';
}