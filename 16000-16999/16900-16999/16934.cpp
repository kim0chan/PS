#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 100000 * 10 + 10;
int nxt[MX][26];
bool chk[MX];
unordered_map<string, int> um;

int c2i(char c) {
    return c - 'a';
}

string insert(string& nickname) {
    string ret = "";
    bool prefix = true;
    int cur = ROOT;
    for(char c : nickname) {
        if(prefix) ret += c;
        if(nxt[cur][c2i(c)] == -1) {
            prefix = false;
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    
    if(chk[cur]) {
        um[nickname]++;
        ret = nickname + to_string(um[nickname]);
    }
    else {
        chk[cur] = true;
        um[nickname] = 1;
    }
    
    return ret;
    
}

int main(void) {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < MX; i++) {
        fill(nxt[i], nxt[i] + 26, -1);
    }
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        string nickname;
        cin >> nickname;
        cout << insert(nickname) << '\n';
    }
}