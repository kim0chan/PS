#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 501;

int M, N;
int map[MAX][MAX];
int dp[MAX][MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int dfs(int x, int y) {
    if (x == M && y == N) { // 도착 지점에 도달하면 1을 리턴
        return 1;
    }

    if (dp[x][y] != -1) { // 이미 계산한 경로이면 DP 값을 이용하여 리턴
        return dp[x][y];
    }

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx > 0 && nx <= M && ny > 0 && ny <= N) { // 범위를 벗어나지 않으면
            if (map[nx][ny] < map[x][y]) { // 현재 위치보다 낮은 곳으로 이동할 수 있으면
                dp[x][y] += dfs(nx, ny); // 이동한 경로의 수를 더해줌
            }
        }
    }

    return dp[x][y];
}

int main() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    memset(dp, -1, sizeof(dp)); // DP 배열 초기화
    cout << dfs(1, 1) << endl;

    return 0;
}