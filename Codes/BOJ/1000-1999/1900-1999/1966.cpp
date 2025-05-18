#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    int N, M, importance;
    for (int i = 0; i < T; i++) {
        int count = 0;
        cin >> N >> M;
        queue<pair<int, int>> qu;
        priority_queue<int> pq;
        for (int j = 0; j < N; j++) {
            cin >> importance;
            qu.push({ j, importance });
            pq.push(importance);
        }
        while (!qu.empty()) {
            auto cur = qu.front();    qu.pop();
            int index = cur.first;
            int value = cur.second;

            if (pq.top() == value) {
                pq.pop();
                count++;
                if (index == M) {
                    cout << count << '\n';
                    break;
                }
            }
            else qu.push({ index, value });
        }
    }
}