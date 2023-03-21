#include <bits/stdc++.h>
using namespace std;

int M, N;
int board[501][501];
int dp[501][501];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int dfs(int x, int y) {
	if (x == M && y == N)	return 1;
	if (dp[x][y] != -1)		return dp[x][y];

	dp[x][y] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 1 || nx > M || ny < 1 || ny > N)	continue;
		if (board[nx][ny] < board[x][y]) {
			dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y];
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++)	cin >> board[i][j];
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 1) << '\n';


}