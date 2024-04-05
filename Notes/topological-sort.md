# 위상 정렬 (Topological Sort)
방향 그래프에서 간선으로 주어진 정점 간 선후관계를 위배하지 않도록 나열하는 정렬
​
* 하나의 그래프에는 여러 개의 위상 정렬 결과가 존재할 수 있다.
* 그래프 내에 사이클이 존재할 경우에는 올바른 위상 정렬이 존재할 수 없다. 선후관계에 모순이 발생하기 때문이다.
  * 위상 정렬은 사이클이 존재하지 않는 방향 그래프에서만 잘 정의된다. 사이클이 존재하지 않는 방향 그래프를 DAG(Directed Acyclic Graph)라고 한다.

> ✔ 문제에서 원소 간의 선후 관계가 주어지고 순서를 정해야 하는 상황이면 위상 정렬을 떠올려 볼 수 있다.
​

## 위상 정렬의 구현
1. 정점과 간선을 실제로 지울 필요 없이 미리 `indegree`의 값을 저장했다가 매번 뻗어나가는 정점들의 `indegree` 값만 1 감소시켜도 과정을 수행 가능
2. `indegree`가 0인 정점을 구하기 위해 매번 모든 정점들을 다 확인하는 대신 목록을 따로 저장하고 있다가 직전에 제거한 정점에서 연결된 정점들만 추가

## 위상 정렬 알고리즘
1. 맨 처음 모든 간선을 읽으며 `indegree` 테이블을 채움
2. `indegree`가 0인 정점들을 모두 큐에 넣음
3. 큐에서 정점을 꺼내어 위상 정렬 결과에 추가
4. 해당 정점으로부터 연결된 모든 정점의 `indegree` 값을 1 감소시킴. 이 때 `indegree`가 0이 되었다면 그 정점을 큐에 추가
5. 큐가 빌 때까지 3, 4번 과정을 반복

```cpp
vector<int> adj[10];
int deg[10];
int n;
​
queue<int> q;
vector<int> result;
for(int i = 1; i <= n; i++)
    if(deg[i] == 0) q.push(i);
while(!q.empty()) {
    int cur = q.front(); q.pop();
    result.push_back(cur);
    for(int nxt : adj[cur]) {
        deg[nxt]--;
        if(deg[nxt] == 0) q.push(nxt);
    ​}
}
if(result.size() != n)
    cout << "cycle exists";
else {
    for(auto x : result) cout << x << ' ';
}
```
* 각 정점은 큐에 최대 1번 들어가고 `indegree`를 감소시키는 연산은 각 간선에 대해 1번씩만 발생하기 때문에 시간복잡도는 $O(V+E)$이다.
* 그래프에서의 BFS/DFS 시간복잡도가 $O(V+E)$인 것과 비슷한 맥락이다.