#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

int maps[100][100];
int visited[100][100];

int dx[8]= { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	while (1) {
		int w, h;
		cin >> w >> h;
		if (!(w * h)) { break; }
		int count = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> maps[i][j];
			}
		}

		/*
		cout << "[DEBUG] v printing module>>\n";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << visited[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//cout << i << ", " << j << " 에서 검사중..\n";
				if (visited[i][j] == 1 || maps[i][j] == 0) { continue; }
				queue<pair<int, int>> qu;
				//cout << i << ", " << j << " 에서 걸려뿟다!\n";
				visited[i][j] = 1;
				qu.push({ i, j });
				count++;

				while (!qu.empty()) {
					pair<int, int> cur = qu.front();	qu.pop();
					for (int dir = 0; dir < 8; dir++) {
						int nx, ny;
						nx = cur.X + dx[dir];
						ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= h || ny < 0 || ny >= w) { continue; }
						if (visited[nx][ny] == 1 || maps[nx][ny] == 0) { continue; }

						visited[nx][ny] = 1;
						//cout << nx << ", " << ny << "의 visited를 1로 설정함.\n";
						qu.push({ nx, ny });
					}
				}
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited[i][j] = 0;
			}
		}

		cout << count << '\n';
	}
	
}