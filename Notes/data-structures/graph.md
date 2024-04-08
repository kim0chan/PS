# 그래프 Graph
* 정점과 간선으로 이루어진 자료구조
* 최단 경로 찾기, 랭킹 정하기와 같이 원소 사이의 연결 관계를 설정해야 하는 상황에서 유용하게 활용되는 자료구조
* 종류
    * 무방향 그래프(Undirected Graph)
    * 방향 그래프(Directed Graph)
    * 순환 그래프(Cyclic Graph)
    * 비순환 그래프(Acyclic Graph)
    * 완전 그래프(Complete Graph)
        * 모든 서로 다른 두 정점 쌍이 간선으로 연결된 그래프
    * 연결 그래프(Connected Graph)
        * 임의의 두 정점 사이에 경로가 항상 존재하는 그래프
    * 단순 그래프(Simple Graph)
        * 두 정점 사이의 간선이 1개 이하이고 루프가 존재하지 않는 그래프

## 그래프의 입력
* 무방향 그래프 예시
```cpp
vector<int> adj[10];
int v, e;
cin >> v >> e;
for(int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

## 복잡도
* 인접 행렬
    * 공간 복잡도 : $O(V^2)$
    * 정점 `u`, `v`가 연결되어 있는지 확인하는 시간 복잡도: $O(1)$
    * 정점 `v`와 연결된 모든 정점을 확인하는 시간 복잡도: $O(V)$
    * 효율적인 상황: 두 점의 연결 여부를 자주 확인할 때, $E$가 $V^2$에 가까울 때
* 인접 리스트 (★)
    * 공간복잡도 : $O(V+E)$
    * 정점 `u`, `v`가 연결되어 있는지 확인하는 시간 복잡도: $O(min(deg(u), deg(v)))$
    * 정점 v와 연결된 모든 정점을 확인하는 시간 복잡도: $O(deg(v))$
    * 효율적인 상황: 특정 정점에 연결된 모든 정점을 자주 확인할 때, $E$가 $V^2$보다 훨씬 작을 때​

## BFS
1. 시작하는 정점을 **큐에 넣고 방문했다는 표시를 남김**
2. 큐에서 **정점을 꺼내어** 그 정점과 연결된 모든 정점들에 대해 3번을 진행
3. 해당 정점을 **이전에 방문했다면 아무 것도 하지 않고**, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 정점을 큐에 삽입
4. 큐가 빌 때까지 2번을 반복
* 모든 정점이 큐에 최대 1번씩 들어가므로 시간복잡도는 인접 리스트에서 $O(V+E)$, 인접 행렬에서 $O(V^2)$의 시간복잡도.

## DFS
* BFS에서 queue를 stack으로 대체한다.
```cpp
vector<int> adj[10];
bool vis[10];
void dfs() {
    stack<int> s;
    s.push(1);
    vis[1] = true;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        cout << cur << ' ';  // 처리 부분
        for(auto nxt : adj[cur]) {
            if(vis[nxt]) continue;
            s.push(nxt);
            vis[nxt] = true;
        }
    }
}
```
* 재귀를 이용한 코드
    * 재귀적으로 호출할 때마다 메모리의 스택 영역에 계속 데이터가 쌓이게 된다.
```cpp
vector<int> adj[10];
bool vis[10];
void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' '; //처리 부분
    for(auto nxt : adj[cur]) {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}
```
* 비재귀 V2
    * 관념적 DFS와 동일하게 동작함.
    * 방문 여부 확인 순서에 유의
```cpp
vector<int> adj[10];
bool vis[10];
void dfs() {
    stack<int> s;
    s.push(1);
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for(auto nxt : adj[cur]) {
            if(vis[nxt]) continue;
            s.push(nxt);
        }
    }
}
```

## 이분 그래프
* `visited`에 숫자를 남기고 인접한 노드의 숫자가 같은지 확인
    * 같으면 이분 그래프가 아님
