# 최소 신장 트리 Minimum Spanning Tree, MST
* 방향성이 없는 그래프(Undirected Graph)의 부분 그래프들 중에서 모든 정점을 포함하고, 간선의 합이 최소인 트리를 의미한다.
* 최소 신장 트리는 동일한 그래프에서 딱 한 개로 정해지지 않고 여러 개일 수 있다.

## 크루스칼 알고리즘
* 구현: Union-Find 알고리즘 이용
* 개념
    1. 간선을 크기의 오름차순으로 정렬하고 제일 낮은 비용의 간선을 선택
    2. 
        * 현재 선택한 간선이 정점 `u`, `v`를 연결하는 간선이라고 할 때 만약 `u`와 `v`가 같은 그룹이라면 아무것도 하지 않고 넘어감.
        * `u`와 `v`가 다른 그룹이라면 같은 그룹으로 만들고 현재 선택한 간선을 최소 신장 트리에 추가
    3. 최소 신장 트리에 (`V - 1`)개의 간선을 추가시켰다면 과정을 종료, 그렇지 않다면 그 다음으로 비용이 작은 간서을 택해 `2`번 과정을 반복

## 프림 알고리즘
* 구현: 우선순위 큐 이용
* 개념
    1. 임의의 정점을 선택해 최소 신장 트리에 추가
    2. 최소 신장 트레이 포함된 정점과 최소 신장 트리에 포함되지 않은 정점을 연결하는 간선 중 비용이 가장 작은 것을 최소 신장 트리에 추가
    3. 최소 신장 트리에 (`V - 1`)개의 간선이 추가될 때까지 `2`번 과정을 반복
        ```cpp
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        tie(a, b, c) = pq.top();    pq.pop();
        ```
* ❗ 인접 리스트와 check용 `bool` 배열이 필요하다.  
또한 인접 리스트에 cost를 넣어야 하므로  
`vector<pair<int, int>> adj[V개수];`  
이렇게 선언한다.

```cpp
#define X first
#define Y second
​
int v, e;
vector<pair<int, int>> adj[10005];
bool chk[10005];
​
cin >> v >> e;
for(int i = 0; i < e; i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({cost, b});
    adj[b].push_back({cost, a});
​}​
​
int cnt = 0;
priority_queue<tuple<int, int, int>,    // 구조에 주의합시다.
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>> pq;
chk[1] = true;    // 출발지에 true 먹여줌💥
for(auto nxt : adj[1])
    pq.push({nxt.X, 1, nxt.Y});
​
while(cnt < v - 1) {   // while문 내부를 잘 보자.
    int cost, a, b;
    tie(cost, a, b) = pq.top();  pq.pop();
    if(chk[b]) continue;
    cout << cost << ' ' << a << ' ' << b << '\n';
    chk[b] = 1;
    cnt++;
    for(auto nxt : adj[b]) {
        if(chk[nxt.Y]) continue;
    ​    pq.push({nxt.X, b, nxt.Y});
    }
}
```

## 전체 연결 못하는 경우
* `N - 1`을 채우기 전에 `pq`가 비거나(`pq.empty()`)
* `cnt`가 `N - 1`이 아니거나
