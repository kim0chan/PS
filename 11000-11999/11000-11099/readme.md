# 11000 ~ 11099


## 11003 : 최솟값 찾기(★)
`deque`를 이용한 기가 막힌 문제  
코드를 자주 보며 기가 막힌 풀이에 감탄하도록 하자.

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

## 11054 : 가장 긴 바이토닉 부분 수열
DP로 풀었다. 배열을 순회하며 해당 인덱스까지 가장 긴 증가하는 부분 수열의 길이, 해당 인덱스부터 가장 긴 감소하는 부분 수열의 길이를 저장한 후 그 둘을 더한 값의 최대값을 출력하는데 이 때 해당 인덱스는 두 번 카운트 되므로 1을 빼주면 된다.

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
