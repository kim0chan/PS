#include <bits/stdc++.h>

using namespace std;

int apt[15][16];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 1; i < 16; i++) {
        apt[0][i] = i;
    }

    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 16; j++) {
            for (int k = 1; k <= j; k++) {
                apt[i][j] += apt[i - 1][k];
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int k, n;
        cin >> k >> n;

        cout << apt[k][n] << '\n';
    }

    return 0;
}