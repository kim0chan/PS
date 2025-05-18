#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

int map_[26][26];
int visited[26][26];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			map_[i][j] = (int)input[j]-48;
		}
	}

	vector<int> numofhouse;
	int numofdanji = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			queue<pair<int, int>> qu;
			int cnt = 0;
			if (visited[i][j] == 1 || map_[i][j] == 0) { continue; }
			visited[i][j] = 1;
			qu.push({ i, j });
			numofdanji++;
			while (!qu.empty()) {
				pair<int, int> cur = qu.front();	qu.pop();
				cnt++;
				for (int dir = 0; dir < 4; dir++) {
					int nx, ny;
					nx = cur.X + dx[dir];
					ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) { continue; }
					if (visited[nx][ny] == 1 || map_[nx][ny] == 0) { continue; }
					visited[nx][ny] = 1;
					qu.push({ nx, ny });
				}
			}
			numofhouse.push_back(cnt);
		}
	}
	sort(numofhouse.begin(), numofhouse.end());
	cout << numofdanji << '\n';
	for (auto i : numofhouse) {
		cout << i << '\n';
	}
}