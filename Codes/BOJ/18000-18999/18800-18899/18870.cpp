#include <bits/stdc++.h>
using namespace std;

int N;
int num[1000001];
vector<int> v;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		v.push_back(num[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < N; i++) {
		cout << lower_bound(v.begin(), v.end(), num[i]) - v.begin() << ' ';
	}
}