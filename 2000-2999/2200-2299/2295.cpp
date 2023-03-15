#include <bits/stdc++.h>
using namespace std;

int N;
int a[1001];
vector<int> added;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) { cin >> a[i]; }
	sort(a, a + N);

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			added.push_back(a[i] + a[j]);
		}
	}
	sort(added.begin(), added.end());
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(added.begin(), added.end(), a[i] - a[j])) {
				cout << a[i];
				return 0;
			}
		}
	}
}