#include <bits/stdc++.h>

using namespace std;

int A[51];
int B[51];
int Astar[51];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + N);

	for (int i = 0; i < N; i++) {
		//cout << "A[" << i << "] * B[" << N - 1 - i << "]\n";
		//cout << A[i] << " * " << B[N - 1 - i] << "\n";
		sum += A[i] * B[N - 1 - i];
	}

	cout << sum << '\n';
}