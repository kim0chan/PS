#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		multiset<int> Q;
		while (k--) {
			char input;
			cin >> input;
			if (input == 'D') {
				int num;
				cin >> num;
				if (Q.empty())	continue;
				if (num == 1)	Q.erase(prev(Q.end()));
				else			Q.erase(Q.begin());
			}
			else {
				int num;
				cin >> num;
				Q.insert(num);
			}
		}
		if (Q.empty())	cout << "EMPTY\n";
		else {
			cout << *prev(Q.end()) << ' ' << *Q.begin() << '\n';
			auto a = Q.begin();
			/*
			while (a != Q.end()) {
				cout << *a << ' ';
				advance(a, 1);
			}
			*/
		}
	}
}