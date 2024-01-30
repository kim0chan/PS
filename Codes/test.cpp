#include <bits/stdc++.h>
#define X   first
#define Y   second
using namespace std;

char board[101][101];
int dist[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solution(vector<string> maps) {
    int answer = -1;
    
    int n = (int)maps.size();
    int m = (int)maps[0].size();
    int start_x, lever_x;
    int start_y, lever_y;
    
    int i = 0;
    for(auto e : maps) {
        for(int j = 0; j < m; j++) {
            board[i][j] = e[j];
            if(e[j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
        i++;
    }
    
    queue<pair<int, int>> qu;
    dist[start_x][start_y] = 1;
    qu.push({start_x, start_y});
    
    bool found = false;
    while(!qu.empty()) {
        if(found)   break;
        pair<int, int> cur = qu.front();    qu.pop();
        
        if(board[cur.X][cur.Y] == 'L') {
            lever_x = cur.X;
            lever_y = cur.Y;
            found = true;
            continue;
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
            if(board[nx][ny] == 'X' || dist[nx][ny])    continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            qu.push({nx, ny});
        }
    }
    
    if(!found)  return -1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == lever_x && j == lever_y)    continue;
            dist[i][j] = 0;
        }
    }
    
    while(!qu.empty())  qu.pop();
    qu.push({lever_x, lever_y});
    found = false;
    
    while(!qu.empty()) {
        if(found)   break;
        pair<int, int> cur = qu.front();    qu.pop();
        
        if(board[cur.X][cur.Y] == 'E') {
            answer = dist[cur.X][cur.Y] - 1;
            break;
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
            if(board[nx][ny] == 'X' || dist[nx][ny])    continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            qu.push({nx, ny});
        }
    }
    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return answer;
}