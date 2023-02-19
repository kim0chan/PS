#include <bits/stdc++.h>

using namespace std;

int room[101][101];

int main() {
    int x_cnt = 0;
    int y_cnt = 0;
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < N; j++) {
            room[i][j] = (input[j] == '.') ? 0 : 1;
        }
    }

    for(int i = 0; i < N; i++) {
        int sec = 0;
        for(int j = 0; j < N; j++) {
            if(room[i][j] == 0) {
                sec++;
                if(sec == 2) {
                    x_cnt++;
                    break;
                }
            }
            else {
                    sec = 0;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        int sec = 0;
        for(int j = 0; j < N; j++) {
            if(room[j][i] == 0) {
                sec++;
                if(sec == 2) {
                    y_cnt++;
                    break;
                }
            }
            else {
                    sec = 0;
            }
        }
    }

    cout << x_cnt << ' ' << y_cnt << '\n';
}