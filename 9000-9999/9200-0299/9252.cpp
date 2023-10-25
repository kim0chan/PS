#include <bits/stdc++.h>
using namespace std;

int DP[1001][1001];
string input_A, input_B;
string lcs = "";

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> input_A >> input_B;
	int size_A = (int)input_A.size();
	int size_B = (int)input_B.size();

	for (int i = 1; i <= size_A; i++) {
		for (int j = 1; j <= size_B; j++) {
			if (input_A[i - 1] == input_B[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	cout << DP[size_A][size_B] << '\n';
	if (!DP[size_A][size_B]) { return 0; }

	int idx = size_B;
	for (int i = size_A; i >= 1; i--) {
		for (int j = idx; j >= 1; j--) {
			if (DP[i][j] == DP[i - 1][j]) {
				idx = j;
				break;
			}
			else if (DP[i][j] == DP[i][j - 1])	continue;
			else	lcs = input_A[i - 1] + lcs;
		}
	}

	cout << lcs << '\n';
}