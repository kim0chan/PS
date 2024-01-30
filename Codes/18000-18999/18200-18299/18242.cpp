#include <bits/stdc++.h>
using namespace std;

int N, M;
bool board[101][101];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int start_r = -1, start_c = -1;
	int side_length = -1;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		int j = 0;
		int temp = 0;
		for (char c : input) {
			if (c == '#') {
				board[i][j] = true;
				temp++;

				if (start_r == -1) {
					start_r = i;
					start_c = j;
				}
			}
			j++;
		}
		side_length = max(temp, side_length);
	}

	if (board[start_r + side_length / 2][start_c] == false)								cout << "LEFT\n";
	else if (board[start_r - 1 + side_length][start_c + side_length / 2] == false)		cout << "DOWN\n";
	else if (board[start_r + side_length / 2][start_c - 1 + side_length] == false)		cout << "RIGHT\n";
	else if (board[start_r][start_c + side_length / 2] == false)						cout << "UP\n";
	else	cout << "???\n";
}