#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> board;
string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int getMinimumScore(int x, int y) {
	int WB_score = 0;
	int BW_score = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			WB_score += (WB[i][j] != board[x + i][y + j]);
			BW_score += (BW[i][j] != board[x + i][y + j]);
		}
	}

	return min(WB_score, BW_score);
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int answer = 0x7fffffff;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		board.push_back(input);
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			answer = min(answer, getMinimumScore(i, j));
		}
	}

	cout << answer << '\n';
}
