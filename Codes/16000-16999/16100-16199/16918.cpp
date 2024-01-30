#include <bits/stdc++.h>
using namespace std;

int R, C, N;
int board[201][201];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < C; j++) {
			board[i][j] = (input[j] == '.') ? -1 : 0;
		}
	}

	if (N % 2 == 0) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << 'O';
			}
			cout << '\n';
		}
		return 0;
	}

	for (int time = 1; time <= N; time++) {
		if (time % 2) {
			// When Bomberman stands back and observes.
			vector<pair<int, int>> explosion_spots;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (board[i][j] == -1)	continue;
					if (time - board[i][j] >= 3)	explosion_spots.push_back({ i, j });
				}
			}

			for (auto coords : explosion_spots) {
				int cx = coords.first;
				int cy = coords.second;

				board[cx][cy] = -1;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cx + dx[dir];
					int ny = cy + dy[dir];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C)	continue;
					board[nx][ny] = -1;
				}
			}
		}
		else {
			// When Bomberman plants bombs in empty cells.
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (board[i][j] == -1)	board[i][j] = time;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == -1)	cout << '.';
			else					cout << 'O';
		}
		cout << '\n';
	}
}