# 1300 ~ 1399


## 1316 : 그룹 단어 체커
('23. 10. 19.) 다시 풀었어요
```cpp
#include <bits/stdc++.h>
using namespace std;

bool isGroupWord(string& word) {
	bool check[26] = { 0, };
	int length = (int)word.size();

	int cur = word[0];
	check[cur - 'a'] = true;
	
	for (int i = 1; i < length; i++) {
		if (cur == word[i])	continue;
		if (check[word[i] - 'a'])	return false;
		cur = word[i];
		check[cur - 'a'] = true;
	}
	return true;
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		if (isGroupWord(input))	ans++;
	}

	cout << ans << '\n';
}
```

## 1330 : 두 수 비교하기

## 1339 : 단어 수학
예시가 GCF + ACDEB인데 이를 수로 풀어보면  
100G + 10C + 1F  
\+ 10000A + 1000C + 100D + 10E + 1B  
= 10000A + 1010C + 100D + 10E + 1F + 1B이다.

따라서 알파벳 별로 합을 해 둔 뒤에 `sort` 함 돌리고 9부터 곱해서 더해주면 된다.  
근데 이 풀이가 바로 떠오르지 않아서 애좀 먹었다.

## 1351 : 무한 수열 (★)
재귀로 풀었는데 시간 제한이 떴다.  
두 가지 접근이 필요했다.  
1. 중복되는 subproblem이 있기 때문에 memoization이 필요하다.
2. 상태 공간이 넓기 때문에($2 \le P, Q \le 10^9$) 해쉬(`unordered_map`)를 사용해야한다.

## 1368 : 물대기
최소신장트리를 이용했는데.. 물을 끌어오지 않고 우물을 파는 것을 어떻게 그래프에 녹여내는가 이런 발상을 실제로 문제를 대면했을 때 할 수 있을지 모르겠다.  
코드 작성 시에는 우물을 파는 cost를 갖는 가상의 노드를 만들었기 때문에 `cnt`를 `N`(노드 개수)까지 세어야 한다는 점에 유의해야 한다. 이거 바로 캐치한 거 좋았다.

## 1389 : 케빈 베이컨의 6단계 법칙
플로이드 알고리즘을 이용했다.  
관련문제 : [11403](https://www.acmicpc.net/problem/11403) 경로 찾기
