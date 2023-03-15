# 3100 ~ 3199


## 3151 : 합이 0
binary search를 이용하여 풀었다. 몇 가지 핵심 아이디어가 있다.
* `students` 배열을 정렬한다.
* 두 학생의 점수 합을 구한다($O(N^2)$)  
이 때, `for` 문에 들어가는 인덱스 및 비교하는 인덱스 값에 주의하자.  
```cpp
for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int* ub = upper_bound(students + j + 1, students + N, -students[i] - students[j]);
			int* lb = lower_bound(students + j + 1, students + N, -students[i] - students[j]);
			solve += (ub - lb);
		}
	}
```
* upper_bound에서 lower_bound 값을 빼서 학생 수를 구한다. 이 때도 idx 값에 주의합시다. 중복하면 안되니까
* 최대 10,000명에서 3명을 뽑게 되기 때문에 정답 변수는 `long long` 으로 선언해야 한다.
