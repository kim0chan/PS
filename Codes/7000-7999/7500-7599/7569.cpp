#include <bits/stdc++.h>

using namespace std;

int box[101][101][101];
int dx[6] = { 0, 0, 1, 0, 0, -1 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 1, 0, 0, -1, 0, 0 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int M, N, H;
	queue<tuple<int, int, int>> qu;
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					qu.push({ i, j, k });
				}
			}
		}
	}

	while (!qu.empty()) {
		tuple<int, int, int> cur = qu.front();
		qu.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nz = get<0>(cur) + dz[dir];
			int ny = get<1>(cur) + dy[dir];
			int nx = get<2>(cur) + dx[dir];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) { continue; }
			if (box[nz][ny][nx] != 0) { continue; }
			box[nz][ny][nx] = box[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			qu.push({ nz, ny, nx });
		}
	}

	int max = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 0) { cout << -1; return 0; }
				max = (max > box[i][j][k]) ? max : box[i][j][k];
			}
		}
	}
	cout << max - 1;
}