#include <bits/stdc++.h>

using namespace std;

#define MAX_ELEM	10

bool r_count[41];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	for (int i = 0; i < 10; i++) {
		int N;
		cin >> N;

		r_count[N % 42] = true;
	}

	int cnt = 0;

	for (int i = 0; i < 42; i++) {
		if (r_count[i]) cnt++;
	}
	
	cout << cnt;

	return 0;
}