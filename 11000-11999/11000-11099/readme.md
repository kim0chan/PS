# 11000 ~ 11099


## 11021 : A+B - 7

## 11022 : A+B - 8

## 11047 : 동전 0

## 11052 : 카드 구매하기

## 11053 : 가장 긴 증가하는 부분 수열
('23. 3. 17.) 다시 풀었다.  
배열을 거꾸로 순회하며 DP 값을 채우는 접근이다.
```cpp
#include <bits/stdc++.h>
using namespace std;

int A[1001], DP[1001];
int N;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	DP[N - 1] = 1;
	
	for (int i = N - 2; i >= 0; i--) {
		int local_max = 0;
		int j = i + 1;
		while (j < N) {
			if (A[j] > A[i])	local_max = max(local_max, DP[j]);
			j++;
		}
		DP[i] = local_max + 1;
	}

	cout << *max_element(DP, DP + N) << '\n';
}
```

## 11055 : 가장 큰 증가하는 부분 수열
DP를 이용한 $O(N^2)$ 풀이  

('23. 3. 17.) 다시 풀었음. 테이블의 정의가 다르니까 그냥 보고 이해하자.  
기존에 푼 방식과 다르게 배열을 거꾸로 순회하며 DP 값을 채우는 접근이다.
```cpp
#include <bits/stdc++.h>
using namespace std;

int A[1001], DP[1001];
int N;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	DP[N - 1] = A[N - 1];

	for (int i = N - 2; i >= 0; i--) {
		int local_max = 0;
		int j = i + 1;

		while (j < N) {
			if (A[j] > A[i])	local_max = max(local_max, DP[j]);
			j++;
		}
		DP[i] = local_max + A[i];
	}

	cout << *max_element(DP, DP + N) << '\n';
}
```

## 11057 : 오르막 수
