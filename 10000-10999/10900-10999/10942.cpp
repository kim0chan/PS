#include <bits/stdc++.h>
using namespace std;
int N, M;
int number[2001];
bool isPalindrome[2001][2001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			isPalindrome[i][j] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i + 1 < N) {
			isPalindrome[i][i + 1] = (number[i] == number[i + 1]);
		}
	}

	for (int k = 2; k < N; k++) {
		for (int i = 0; i < N; i++) {
			if (i + k >= N)	break;
			isPalindrome[i][i + k] = (isPalindrome[i + 1][i - 1 + k] && number[i] == number[i + k]);
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << isPalindrome[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	cin >> M;
	while (M--) {
		int S, E;
		cin >> S >> E;

		cout << isPalindrome[S - 1][E - 1] << '\n';
	}
	
}