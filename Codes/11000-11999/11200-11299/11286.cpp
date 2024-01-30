#include <bits/stdc++.h>

#define MIN(a, b)	a<b ? a:b
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	priority_queue<int, vector<int>, cmp> pq;

	int N;
	cin >> N;

	while (N--) {
		int input;
		cin >> input;

		if (!input) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}

		else {
			pq.push(input);
		}
	}
}