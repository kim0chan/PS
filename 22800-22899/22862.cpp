#include <bits/stdc++.h>
using namespace std;

#define MAX(a, b)   a > b ? a : b

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> series(N);
    for(int i = 0; i < N; i++) {
        cin >> series[i];
    }
    
    int en = 0, solve = 0, erase = 0;
    
    while(series[en] % 2) en++;
    
    for(int st = en; st < N; st++) {
        while(en < N - 1 && erase + series[en + 1] % 2 <= K) {
            en++;
            erase += series[en] % 2;
        }
        solve = MAX(solve, en - st + 1 - erase);
        erase -= series[st] % 2;
    }
    
    
    cout << solve << '\n';
}