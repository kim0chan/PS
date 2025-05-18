#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int a, b, c;
    
    cin >> a >> b >> c;
    
    cout << (a+b)%c << '\n';
    cout << ((a%c) + (b%c))%c << '\n';
    cout << (a*b)%c << '\n';
    cout << ((a%c) * (b%c))%c << '\n';
}