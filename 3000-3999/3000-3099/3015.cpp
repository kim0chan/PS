#include <bits/stdc++.h>
using namespace std;
#define X	first
#define Y	second

int N;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>> st;
	long long answer = 0;

	cin >> N;
	while (N--) {
		int height;
		cin >> height;
		int count = 1;

		while (!st.empty() && st.top().X <= height) {
			answer += st.top().Y;
			if (st.top().X == height) count += st.top().Y;
			st.pop();
		}

		if (!st.empty()) answer++;
		st.push({ height, count });
	}

	cout << answer << '\n';
}