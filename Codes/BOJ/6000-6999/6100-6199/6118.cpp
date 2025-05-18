#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
vector<int> adj[20001];
int visited[20001];
int barn_num = 20001, max_distance, num_barn;

void BFS() {
    queue<int> qu;
    qu.push(1);
    visited[1] = 1;
    
    while(!qu.empty()) {
        int cur = qu.front();   qu.pop();
        if(max_distance < visited[cur]) {
            barn_num = 20001;
            max_distance = visited[cur];
            num_barn = 0;
        }
        
        if(max_distance == visited[cur]) {
            barn_num = min(barn_num, cur);
            num_barn++;
        }
        
        for(auto next : adj[cur]) {
            if(visited[next])   continue;
            qu.push(next);
            visited[next] = visited[cur] + 1;
        }
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
    
    BFS();
    cout << barn_num << ' ' << max_distance - 1 << ' ' << num_barn << '\n';
}