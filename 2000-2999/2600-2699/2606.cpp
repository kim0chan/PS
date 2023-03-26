#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
vector<int> adj[101];
bool visited[101];
int solve;

void DFS(int V) {
    visited[V] = true;
    solve++;
    
    for(auto next : adj[V]) {
        if(visited[next])   continue;
        DFS(next);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    DFS(1);
    
    cout << solve - 1 << '\n';
}