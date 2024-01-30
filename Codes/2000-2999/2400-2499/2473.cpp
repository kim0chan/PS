#include <bits/stdc++.h>
#define ll    long long
using namespace std;

int main(void) {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<ll> solutions(N);
    for(int i = 0; i < N; i++) {
        cin >> solutions[i];
    }
    sort(solutions.begin(), solutions.end());
    
    ll ans1 = 1e9+1;
    ll ans2 = 1e9+1;
    ll ans3 = 1e9+1;
    
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            int idx = lower_bound(solutions.begin(), solutions.end(), -solutions[i]-solutions[j]) - solutions.begin();
            
            for(int d = -2; d <= 2; d++) {
                if(idx+d == i || idx+d == j)    continue;
                if(idx+d < 0 || idx+d >= N)     continue;
                if(abs(solutions[i]+solutions[j]+solutions[idx+d]) < abs(ans1+ans2+ans3)) {
                    ans1 = solutions[i];
                    ans2 = solutions[j];
                    ans3 = solutions[idx+d];
                }
            }
        }
    }
    
    vector<int> ans;
    ans.push_back(ans1);
    ans.push_back(ans2);
    ans.push_back(ans3);
    sort(ans.begin(), ans.end());
    for(int e : ans) {
        cout << e << ' ';
    }
}