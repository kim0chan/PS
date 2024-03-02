# C++ STL queue(큐)
```cpp
#include <queue>
// ...
queue<int> Q;
// rear(back, 뒤)에 추가하고 front(앞)에서 제거함
```

## 큐의 성질
1. 원소 추가/제거 $O(1)$
2. 앞/뒤 원소 확인 $O(1)$
3. 앞/뒤가 아닌 원소들의 확인/변경이 원칙적으로 불가능

## 멤버 함수
* ❗ 큐가 비어있을 때 원소 참조를 하면 런타임 에러가 일어나겠죠?
  * `front()`, `back()`, `pop()` 등 사용 시 주의
```cpp
queue<int> Q;
Q.empty();
Q.size();
Q.front();
Q.back();
Q.push(val);
Q.pop();
```

## 큐의 초기화
* ❗ queue는 `clear()` 함수가 없다.
  ```cpp
  queue<int> q;
  q.push(1);
  cout << q.size() << "\n";

  q = queue<int>();
  cout << q.size() << "\n";
  ```
  맥 빠지지만 이렇게 초기화한다고 한다.
