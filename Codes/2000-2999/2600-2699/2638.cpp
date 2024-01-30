#include <bits/stdc++.h>
#define	X	first
#define	Y	second
using namespace std;

int N, M;
bool board[101][101];
bool visited[101][101];
int counts[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool ThereIsCheese() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j])	return true;
		}
	}
	return false;
}

void Melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (counts[i][j] >= 2)	board[i][j] = false;
		}
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	while (ThereIsCheese()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
				counts[i][j] = 0;
			}
		}

		queue<pair<int, int>> qu;
		qu.push({ 0, 0 });
		visited[0][0] = true;

		while (!qu.empty()) {
			auto cur = qu.front();	qu.pop();
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
				if (board[nx][ny]) {
					counts[nx][ny]++;
					continue;
				}
				if (visited[nx][ny])	continue;
				else {
					qu.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}

		ans++;
		Melt();
	}



	cout << ans << '\n';
}