#include <bits/stdc++.h>
using namespace std;

int N;
bool sieve[1000001];
int score[1000001];

void solve(int k, int& MX) {
    for(int cur = k+k; cur <= MX; cur+=k) {
        if(!sieve[cur]) continue;
        score[cur]--;
        score[k]++;
    }
}

int main(void) {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int MX = 0;
    cin >> N;
    vector<int> input(N);
    for(int i = 0; i < N; i++) {
        cin >> input[i];
        MX = max(MX, input[i]);
        sieve[input[i]] = true;
    }
    
    for(int k : input) {
        solve(k, MX);
    }
    
    for(int k : input) {
        cout << score[k] << ' ';
    }
    cout << '\n';
    
}