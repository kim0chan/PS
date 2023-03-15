#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	unordered_map<string, int> um(N);
	string strmap[100004];
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> strmap[i];
		um[strmap[i]] = i;
	}

	while (M--) {
		string question;
		cin >> question;
		if (isdigit(question[0]))	cout << strmap[stoi(question)] << '\n';
		else	cout << um[question] << '\n';
	}
}