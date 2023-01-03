#include <bits/stdc++.h>

using namespace std;

priority_queue<int> qu[6];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, P;
	cin >> N >> P;

	int count = 0;
	while (N--) {
		int num, fret;
		cin >> num >> fret;

		if (qu[num].empty() || qu[num].top() < fret) {
			qu[num].push(fret);
			count++;
		}
		else {
			if (qu[num].top() == fret) {
				;
			}
			else {
				while (!qu[num].empty() && qu[num].top() > fret) {
					count++;
					qu[num].pop();
				}
				if (qu[num].empty()) {
					qu[num].push(fret);
					count++;
				}
				else if (qu[num].top() < fret) {
					qu[num].push(fret);
					count++;
				}
				else {
					;
				}
			}
		}
	}
	cout << count << '\n';
}