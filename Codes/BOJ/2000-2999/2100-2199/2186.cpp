#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int DP[101][101][81];
int N, M, K, ans;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
string key;
int len;

int DFS(int x, int y, int idx) {
	if (DP[x][y][idx] != -1)	return DP[x][y][idx];
	if (idx == len)	return 1;
	DP[x][y][idx] = 0;

	for (int dir = 0; dir < 4; dir++) {
		for (int step = 1; step <= K; step++) {
			int nx = x + dx[dir] * step;
			int ny = y + dy[dir] * step;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
			if (board[nx][ny] != key[idx] - 'A')	continue;

			DP[x][y][idx] += DFS(nx, ny, idx + 1);
		}
	}

	return DP[x][y][idx];
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j] - 'A';
		}
	}
	cin >> key;
	len = (int)key.length();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			fill(DP[i][j], DP[i][j] + len + 1, -1);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == key[0] - 'A')	ans += DFS(i, j, 1);
		}
	}

	cout << ans << '\n';
}