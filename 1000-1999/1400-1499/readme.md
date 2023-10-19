# 1400 ~ 1499


## 1406 : 에디터
스택 진국 문제  
한 줄로 된 간단한 에디터

## 1427 : 소트인사이드
정렬  
계수 정렬(Counting Sort) 하면 메모리 효율 더 좋음
```cpp
#include <bits/stdc++.h>
using namespace std;

int N;
int cnt[11];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N) {
		cnt[N % 10]++;
		N /= 10;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i;
		}
	}
	cout << '\n';
}
```

## 1431 : 시리얼 번호
`char`형의 숫자를 `int`형으로 바꿀 때는 `'0'`을 빼면 된다.  
문자열 처리하는 부분을 잘 보면 좋을 듯.

## 1463 : 1로 만들기
DFS로 풀긴 했는데 DP로 풀이할 수 있음.  
힌트: `D[1] = 0`로 두고 역순으로 올라가기 ..
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> dp(N + 1);
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)	dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)	dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N] << '\n';
}
```
DFS가 더 빠르긴 하네

## 1475 : 방 번호

