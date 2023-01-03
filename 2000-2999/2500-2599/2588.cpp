#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int a, b;
    cin >> a >> b;
    int result = a * b;
    
    while(b) {
        cout << a * (b%10) << '\n';
        b = b / 10;
    }
    
    cout << result << '\n';
    
}