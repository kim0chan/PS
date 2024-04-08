# 다익스트라 알고리즘 Dijkstra Algorithm
* 하나의 시작점으로부터 다른 모든 정점까지의 최단 거리를 구하는 알고리즘
* 플로이드 알고리즘은 모든 정점 쌍 사이의 최단 거리를 구하는 알고리즘인 반면 다익스트라 알고리즘은 하나의 시작점으로부터 다른 모든 정점까지의 최단 거리를 구하는 알고리즘이다.
* 플로이드 알고리즘은 음수인 간선이 있는건 상관이 없고 음수인 사이클이 있을 때에만 문제가 발생했지만 다익스트라 알고리즘은 음수의 가중치를 가지는 간선이 있으면 아예 사용할 수 없다.
  * 벨만포드 알고리즘를 별도로 공부하여 사용하자.
  * 음수 간선을 처리할 수 없는 이유
    * 음수 간선이 있으면 현재 갈 수 있는 정점 중에서 가장 가까운 정점까지의 거리를 확정할 수가 없다.

## 구현
1. 우선순위 큐에 `(0, 시작점)`을 추가
2. 우선순위 큐에서 거리가 가장 작은 원소를 선택, 해당 거리가 최단 거리 테이블에 있는 값과 다를 경우 3번 과정을 수행하지 않고 넘어감
3. 원소가 가리키는 정점을 `v`라고 할 때, `v`와 이웃한 정점들에 대해 최단 거리 테이블 값보다 `v`를 거쳐가는 것이 더 작은 값을 가질 경우 최단 거리 테이블의 값을 갱신하고 우선순위 큐에 `(거리, 이웃한 정점의 번호)`를 추가
4. 우선순위 큐가 빌 때까지 2, 3번 과정을 반복
```cpp
#include <bits/stdc++.h>
using namespace std;
​
#define X first
#define Y second
​
int v, e, st;
​
// {비용, 정점 번호}
vector<pair<int, int>> adj[20005];
const int INF = 1e9+10;
int d[20005];
int main(void) {
    sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> st;
    fill(d, d + v + 1, INF);
    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
    d[st] = 0;  // 시작점
    pq.push({d[st], st});  // 우선순위 큐에 (0, 시작점) 추가​
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;  // 거리가 d에 있는 값과 다를 경우 넘어감
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;  // cur를 거쳐가는 것이 더 작은 값을 가질 경우 d[nxt.Y]를 갱신하고 우선순위 큐에 {거리, nxt.Y}를 추가
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
}
```
## 경로 복원 방법
최단 거리 테이블과 더불어 시작점에서 나에게 올 때 직전에 어디를 방문했는지 기록하는 테이블인 `pre` 테이블을 둔다.
```cpp
// for문 내부
if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
d[nxt.Y] = d[cur.Y] + nxt.X;
pq.push({d[nxt.Y], nxt.Y});
pre[nxt.Y] = cur.Y;  // 최단 거리의 갱신이 일어날 때 pre 값을 갱신한다.
```
```cpp
{
    // 생략
    cout << d[en] << '\n';
​    vector<int> path;
​    int cur = en;
​    while(cur != st) {
​        path.push_back(cur);
​        cur = pre[cur];
​    }
​    path.push_back(cur);
​    reverse(path.begin(), path.end());
​    cout << path.size() << '\n';
​    for(auto x : path) cout << x << ' ';
}
```
* 하나의 시작점에서 다른 모든 정점까지의 거리나 경로를 구하는 것이 아니라 하나의 시작점에서 하나의 끝점까지의 거리나 경로를 구하는 상황이라고 하더라도 다익스트라 알고리즘을 쓰면 된다는 것을 알 수 있다.
