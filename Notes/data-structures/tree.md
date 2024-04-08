# 트리 Tree
무방향이면서 사이클이 없는 연결 그래프(Undirected Acyclic Connected Graph)  
= 연결 그래프이면서 임의의 간선을 제거하면 연결 그래프가 아니게 되는 그래프  
= 임의의 두 점을 연결하는 simple path(정점이 중복해서 나오지 않는 경로)가 유일한 그래프  
= 💥 $V$개의 정점을 가지고 $V-1$개의 간선을 가지는 연결 그래프  
= 사이클이 없는 연결 그래프이면서 임의의 간선을 추가하면 사이클이 생기는 그래프  
= $V$개의 정점을 가지고 $V-1$개의 간선을 가지는 Acyclic(= 비순환. 사이클이 없는) 그래프

* 트리에서는 임의의 노드를 루트로 만들 수 있다.

## BFS
* 기본적으로 트리는 그래프의 특별한 한 종류이기 때문에 그래프의 BFS, DFS 알고리즘을 그대로 적용시킬 수 있다.
* 트리의 BFS에서는 살짝 독특한 점이 있는데, 루트가 아닌 아무 정점이나 잡고 생각을 해보면 인접한 정점들 중에 자신의 부모를 제외하고는 전부 자신의 자식이라 아직 방문하지 않았다.  
  * 즉 자신과 이웃한 정점들에 대해 부모만 빼고 나머지는 전부 큐에 넣으면 된다.
  * → **`vis` 배열을 들고 갈 필요가 없이 그냥 부모가 누구인지만 저장하고 있으면 된다.**  
  부모의 정보는 BFS를 돌리면서 자식 정점을 큐에 집어넣을 때 채워줄 수 있다.

```cpp
vector<int> adj[10];
int p[10];  // 배열 선언
void bfs(int root) {
    queue<int> q;
    q.push(root);   // root를 넣고 탐색 시작
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]) {
            // 방문 여부를 확인하는 대신 nxt가 cur의 parent인지 확인
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
}
```

### DFS
* 자신과 연결된 정점들은 1개만 부모이고 나머지는 전부 자식이라는 성질을 이용해  
`vis` 배열을 쓰는 대신 부모 배열과 `depth` 배열을 채우면서 처리가 가능하다.
```cpp
// (1) 부모 배열과 depth 배열 이용. 비재귀
vector<int> adj[10];
int p[10];
int depth[10];
void dfs(int root) {
    stack<int> s;
    s.push(root);
    while(!s.empty()) {
      ​  int cur = s.top();
    ​    s.pop();
    ​    cout << cur << ' ';
    ​    for (int nxt : adj[cur]) {
    ​        if(p[cur] == nxt) continue;
    ​        s.push(nxt);
    ​        p[nxt] = cur;
    ​        depth[nxt] = depth[cur] + 1;
    ​    }
    ​}
}
```
```cpp
// (2) 부모와 depth 배열 채우기, 재귀
vector<int> adj[10];
int p[10];
int depth[10];
void dfs(int cur) {
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        depth[nxt] = dapth[cur] + 1;
        dfs(nxt);
    }
}
```
* 스택 메모리가 1MB로 제한되어 있을 땐 $V$가 대략 3만 이상일 때 1-2-3-4-5-6-... 형태의 일자 트리 모양에서  
스택 메모리 한계를 넘어설 수 있기 때문에 주의해야 한다.
```cpp
// (3) 단순 순회, 재귀
vector<int> adj[10];
void dfs(int cur, int par) {
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
        if (par == nxt) continue;
        dfs(nxt, cur);
    }
}
// call dfs(1, 0);
```
* 부모 배열이나 depth 배열을 굳이 저장할 필요가 없고 단순 순회가 목적이라면 코드가 훨씬 간결해진다.  
그냥 함수 인자로 parent를 넘겨주면 된다.
* 간결하게 재귀를 이용한 DFS를 할 때 쓰면 좋다.

## 이진 트리 (binary tree)
각 정점의 자식이 최대 2개인 트리

### 이진 트리의 순회
이진 트리의 순회에는 따로 이름이 붙은 순회들이 있다.
1. 레벨 순회
2. 전위 순회
3. 중위 순회
4. 후위 순회

물론 기존 방식대로 순회를 할 수는 있지만 그렇게 처리를 해버리면 왼쪽 자식과 오른쪽 자식을 구분할 수가 없기 때문에 인접 리스트를 이용한 방법 대신 왼쪽 자식과 오른쪽 자식을 저장하게끔 코드를 구성하면 좋다.

`lc`, `rc`, `parent` 배열을 두어서 관리할 수 있고, `parent` 배열은 사용하지 않더라도 순회 시에는 문제가 없다.  
필요하면 만들어 쓰자
​
### 레벨 순회
레벨, 즉 높이 순으로 방문하는 순회이다.  
**루트에서 BFS를 돌리면 자연스럽게 레벨 순회**가 되기 때문에, 루트를 시작점으로 두고 BFS를 돌리면 된다.
```cpp
int lc[9] = {0,2,4,6,0,0,0,0,0};
int rc[9] = {0,3,5,7,0,8,0,0,0};
void bfs() {
    queue<int> q;
    q.push(1);    // root = 1
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        if(lc[cur]) q.push(lc[cur]);
        if(rc[cur]) q.push(rc[cur]);
    }
}
```

### 전위 순회 (DFS와 방문 순서가 동일)
```cpp
int lc[9] = {0,2,4,6,0,0,0,0,0};
int rc[9] = {0,3,5,7,0,8,0,0,0};
void preorder(int cur) {
    cout << cur << ' ';
    if(lc[cur] != 0) preorder(lc[cur]);
    if(rc[cur] != 0) preorder(rc[cur]);
}
```

### 중위 순회
```cpp
int lc[9] = {0,2,4,6,0,0,0,0,0};
int rc[9] = {0,3,5,7,0,8,0,0,0};
void inorder(int cur) {
    if(lc[cur] != 0) inorder(lc[cur]);​
    cout << cur << ' ';
    if(rc[cur] != 0) inorder(rc[cur]);
}
```

### 후위 순회
```cpp
int lc[9] = {0,2,4,6,0,0,0,0,0};
int rc[9] = {0,3,5,7,0,8,0,0,0};
void postorder(int cur) {
    if(lc[cur] != 0) postorder(lc[cur]);
    if(rc[cur] != 0) postorder(rc[cur]);
cout << cur << ' ';​
}
```
