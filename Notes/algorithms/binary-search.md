# 이분탐색 Binary Search
```cpp
#include <algorithm>
```

## 이분탐색 Binary Search
* **정렬되어 있는 배열**에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로 확인하는 대신 탐색 범위를 절반으로 줄여가며 찾는 탐색 방법
> 직접 이분탐색을 짰을 때 무한 루프에 빠지는 게 걱정되면 st와 en이 1 차이날 때를 주의 깊게 확인하자.​
```cpp
bool binarySearch(int target) {  // 💥 탐색 대상이 되는 배열이 이미 오름차순으로 정렬되어 있어야 함.
	int st = 0, en = N - 1;
	while (st <= en) {
		int mid = (st + en + 1) / 2;
​
		if (A[mid] < target)	     st = mid + 1;
		else if (A[mid] > target)  en = mid - 1;
		else return true;  // 탐색 성공! 이럼 target과 같은 값을 찾은거니까
	}
​
	return false;  // 탐색 실패! st > en일 경우 while문을 탈출
}
```

## STL 이분탐색 (`binary_search()`)
* STL에는 `binary_search` 함수가 있어서 범위를 주면 주어진 범위 내에 원소가 들어있는지 여부를 $O(\lg N)$에 `true` 혹은 `false`로 알려준다.
  * 💥 단, 범위는 반드시 오름차순으로 정렬되어 있어야 한다.
```cpp
int a[100005];​
int n;
​
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int m;
    cin >> m;
    while(m--) {
        int t;
        cin >> t;
        cout << binary_search(a, a+n, t) << '\n';
    }
}
```
> ❗ `vector`에서 탐색을 할 경우 `v.begin()`, `v.end()`를 인자로 넘겨주면 된다.

## 중복 원소 개수 찾기
* `lower_bound`는 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾아줌
* `upper_bound`는 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 찾아줌
* `equal_range`는 (`lower_bound`, `upper_bound`)의 쌍(`std::pair` 객체)을 리턴함​
  * 💥 일단 정렬 후, `lower_bound(arr, arr + 6, 6) - arr;` 이런 식으로 사용
    * 시작 주소를 빼주는 이유는 인덱스 번호를 반환하게 하기 위함.
  * 만약에 찾으려는 key 값이 없으면 어떻게 될까 ?
    * 배열 끝을 반환함.(예시에선 `arr + 6`)
* 💥 배열이 정렬되어 있을 때, 값의 개수를 찾아내기 위해서 `upper_bound`에서 `lower_bound`를 빼는 아이디어가 유효하다.​

## 좌표 압축
* 입력으로 주어지는 값의 범위에 비해 입력의 개수가 턱없이 작을 때 배열의 값에 새로운 인덱스를 부여하는 기술
* [18870] 좌표 압축의 문제를 보면 들어올 수 있는 값이 양과 음의 방향으로 각각 10의 9승이나 된다.
* 따라서 들어오는 좌표를 순서대로 정렬하고 중복을 제거하여 새로운 좌표 배열을 만든다.
```cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```
* 압축된 배열에서 원래 배열의 원소 위치를 찾고 싶을 땐 `lower_bound()` 함수로 해당 원소의 인덱스를 찾는다.
```cpp
int index = lower_bound(v.begin(), v.end(), num) - v.begin();
```

## Parametric Search
* 조건을 만족하는 최소/최댓값을 구하는 문제(최적화 문제)를 결정 문제로 변환해 이분탐색을 수행하는 방법
  * (최적화 문제) N개를 만들 수 있는 랜선의 최대 길이
  * (결정 문제) 랜선의 길이가 X일 때 랜선이 N개 **이상인가 아닌가**?​
* 이분탐색을 수행할 변수를 가지고 함수를 세웠을 때 그 함수가 증가함수거나 감소함수여야 한다.
  * → 최적화 문제를 결정 문제로 바꿀 수 있는지 생각하고 얻어낸 함수가 증가 혹은 감소함수 형태인지 따져봐야 한다.
## Java 이분 탐색
```java
int left = 1;         // 최소값
int right = 100_000;  // 최대값

while (left <= right) {
  int mid = (left + right) / 2;
  if (mid < target)       left  = mid + 1;
  else if (mid > target)  right = mid - 1;
  else return true;
}

return false;
```
```java
// Parametric Search
class Solution {
    public int solution() {
        int st = 1;        // 최소값
        int en = 100_000;  // 최대값
        int answer = en;
        
        while (st <= en) {
            int mid = (st + en - 1) / 2;
            if (isClearable()) {
                answer = mid;
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return answer;
    }
    
    private boolean isClearable() {
	    // Black-box determination method
        if (applicable)  return true;
        else             return false
    }
}
```
### 🔹 식 비교

#### 1. `int mid = left + (right - left) / 2;`
- 👉 **중간 값이 왼쪽 절반에 치우침** (`lower mid`)
- 일반적인 이진 탐색에서 **왼쪽으로 수렴**할 때 사용한다.
- 예를 들어, `left = 3`, `right = 4`일 때:
    - `(3 + (4 - 3) / 2) = 3`
#### 2. `int mid = left + (right - left + 1) / 2;`
- 👉 **중간 값이 오른쪽 절반에 치우침** (`upper mid`)
- **오른쪽으로 수렴**하고 싶을 때 사용한다.
- 같은 상황, `left = 3`, `right = 4`일 때:
    - `(3 + (4 - 3 + 1) / 2) = 4`
### 🔹 언제 어떤 걸 써야 할까?

- `mid = (left + right) / 2` (혹은 첫 번째 방식):  
    → 보통 `조건을 만족하면 right = mid - 1`처럼 **오른쪽을 줄이는** 경우에 사용한다.  
    → 즉, **최솟값을 찾는 경우**.
    
- `mid = (left + right + 1) / 2` (두 번째 방식):  
    → 보통 `조건을 만족하면 left = mid`처럼 **왼쪽을 줄이지 않고 유지**하고 **오른쪽으로 확장**할 때 사용한다.  
    → 즉, **최댓값을 찾는 경우**.

즉, 둘 다 convergence는 되지만,  
탐색 구간을 어떻게 업데이트하느냐에 따라 어느 mid 계산법이 더 안전하고 직관적인지가 달라진다.