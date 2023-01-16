#include <bits/stdc++.h>

#define X	first
#define Y	second
using namespace std;

int N;
int rainmap[101][101];
bool visited[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void printingModule() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	int min = 150;
	int max = -1;
	int solve = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> rainmap[i][j];
			min = min < rainmap[i][j] ? min : rainmap[i][j];
			max = max > rainmap[i][j] ? max : rainmap[i][j];
		}
	}

	int phase = min;
	while (phase <= max) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (rainmap[i][j] < phase || visited[i][j]) { continue; }
				cnt++;
				queue<pair<int, int>> qu;
				visited[i][j] = 1;
				qu.push({ i, j });

				while (!qu.empty()) {
					pair<int, int> cur = qu.front();	qu.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) { continue; }
						if (rainmap[nx][ny] < phase || visited[nx][ny]) { continue; }
						visited[nx][ny] = 1;
						qu.push({ nx, ny });
					}
				}
			}
		}
		solve = solve > cnt ? solve : cnt;
		phase++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}
	}

	cout << solve << '\n';
}