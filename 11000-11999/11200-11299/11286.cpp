#include <bits/stdc++.h>

#define MIN(a, b)	a<b ? a:b
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	priority_queue<int> negpq;
	priority_queue<int, vector<int>, greater<int>> pospq;

	int N;
	cin >> N;

	while (N--) {
		int input;
		int ret;
		cin >> input;

		if (!input) {
			// pop
			if (negpq.empty() || pospq.empty()) {
				if (negpq.empty() && pospq.empty()) {
					ret = 0;
				}
				else if (negpq.empty()) {
					ret = pospq.top();	pospq.pop();
				}
				else {
					ret = negpq.top();	negpq.pop();
				}
			}
			else {
				if (abs(negpq.top()) > pospq.top()) {
					ret = pospq.top();	pospq.pop();
				}
				else {
					ret = negpq.top();	negpq.pop();
				}
			}
			cout << ret << '\n';
		}
		else {
			if (input < 0) {
				negpq.push(input);
			}
			else {
				pospq.push(input);
			}
		}
	}
}