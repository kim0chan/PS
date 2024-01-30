#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

string board[101];
int visited[101][101];
int disabled_visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int normal = 0;
	int handicapped = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 1) { continue; }
			queue<pair<int, int>> qu;
			char sch = board[i][j];
			visited[i][j] = 1;
			normal++;
			qu.push({ i, j });

			while (!qu.empty()) {
				pair<int, int> cur = qu.front();
				qu.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx, ny;
					nx = cur.X + dx[dir];
					ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) { continue; }
					if (visited[nx][ny] == 1 || board[nx][ny] != sch) { continue; }
					visited[nx][ny] = 1;
					qu.push({ nx, ny });
				}
			}
		}
	}
	cout << normal << ' ';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (disabled_visited[i][j] == 1) { continue; }
			queue<pair<int, int>> qu;
			char sch = board[i][j];
			visited[i][j] = 1;
			handicapped++;
			qu.push({ i, j });

			while (!qu.empty()) {
				pair<int, int> cur = qu.front();
				qu.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx, ny;
					nx = cur.X + dx[dir];
					ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) { continue; }
					if (disabled_visited[nx][ny] == 1) { continue; }
					if (board[nx][ny] == 'R' && sch == 'B') { continue; }
					if (board[nx][ny] == 'B' && sch == 'R') { continue; }
					if (board[nx][ny] == 'G' && sch == 'B') { continue; }
					if (board[nx][ny] == 'B' && sch == 'G') { continue; }
					disabled_visited[nx][ny] = 1;
					qu.push({ nx, ny });
				}
			}
		}
	}

	cout << handicapped;

}