#include <bits/stdc++.h>
#define ll	long long
using namespace std;

int N;

class cmp {
public:
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		if (a.first != b.first)	return a.first > b.first;
		else return a.second < b.second;
	}
};

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	ll ans = 0;
	int t = 1;

	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	priority_queue<int, vector<int>, greater<int>> temp;
	while (N--) {
		int deadline, ramen;
		cin >> deadline >> ramen;
		pq.push({ deadline, ramen });
	}

	while (!pq.empty()) {
		auto cur = pq.top();	pq.pop();
		if (t <= cur.first) {
			temp.push(cur.second);
			t++;
		}
		else {
			if (temp.top() < cur.second) {
				temp.pop();
				temp.push(cur.second);
			}
		}
	}

	while (!temp.empty()) {
		ans += temp.top();
		//cout << "+" << temp.top() << "\n";
		temp.pop();
	}

	cout << ans << '\n';
}