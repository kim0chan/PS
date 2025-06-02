# 부분 집합 완전 탐색 (in Java)
## 비트마스킹
```java
class Solution {
	public int solution(int[][] data, int a, int b) {
		int answer = 0;
		int n = data.length;
		
		// 1 << n == 2^n, 모든 부분집합 탐색
		for (int i = 1; i < (1 << n); i++) {
			int aSum = 0;
			int bSum = 0;
			
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) != 0) {
					aSum += data[j][0];
					bSum += data[j][1];
				}
			}
			
			if (aSum <= a && bSum >= b) {
				answer++;
			}
		}
		
		return answer;
	}
}
```
## 백트래킹
```java
class Solution {
	int answer = 0;
	int[][] data;
	int a, b;

	public int solution(int[][] data, int a, int b) {
		this.data = data;
		this.a = a;
		this.b = b;
		backtrack(0, 0, 0);
		return answer;
	}
	
	private void backtrack(int index, int aSum, int bSum) {
		if (bSum > b)  return;
		
		if (aSum >= a && bSum <= b && index > 0) {
			answer++;
		}
		
		for (int i = index; i < data.length; i++) {
			backtrack(i + 1,
								aSum += data[i][0],
								bSum += data[i][1]);
		}
	}
}
```
- `backtrack` 함수의 `if` 문 내부 `index > 0` 조건은 공집합을 제외하는 역할을 한다.