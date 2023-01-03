#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

int board[101][101];
int distancearr[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = (int)(input[j] - 48);
		}
	}

	int dist = 1;

	queue<pair<int, int>> qu;
	distancearr[0][0] = 1;
	qu.push({ 0, 0 });

	while (!qu.empty()) {
		pair<int, int> cur = qu.front();
		qu.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) { continue; }
			if (distancearr[nx][ny] != 0 || board[nx][ny] == 0) { continue; }
			distancearr[nx][ny] = distancearr[cur.X][cur.Y] + 1;
			qu.push({ nx, ny });
		}
	}

	cout << distancearr[N - 1][M - 1];

}