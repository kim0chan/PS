#include <bits/stdc++.h>
using namespace std;

string cmd;
int N, M, a, b, p;
int DofP[100001];
set<int> PofD[101];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	while (N--) {
		cin >> a >> b;
		DofP[a] = b;
		PofD[b].insert(a);
	}

	cin >> M;
	while (M--) {
		cin >> cmd;
		if (cmd == "recommend") {
			cin >> p;
			if (p == 1) {
				for (int i = 100; i >= 0; i--) {
					if (PofD[i].empty())	continue;
					cout << *(prev(PofD[i].end())) << '\n';
					break;
				}
			}
			else {
				for (int i = 0; i < 101; i++) {
					if (PofD[i].empty())	continue;
					cout << *(PofD[i].begin()) << '\n';
					break;
				}
			}
		}
		else if (cmd == "add") {
			cin >> a >> b;
			DofP[a] = b;
			PofD[b].insert(a);
		}
		else if (cmd == "solved") {
			cin >> a;
			PofD[DofP[a]].erase(a);
		}
	}
}