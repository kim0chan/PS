# C++ STL priority queue (우선순위 큐)
```cpp
#include <queue>
```

## 우선순위 큐
* pop을 할 때 가장 먼저 들어온 원소가 나오는 대신 우선순위가 가장 높은 원소가 나오는 큐
1. 원소의 추가가 O(lg N)
2. 우선순위가 가장 높은 원소의 확인이 O(1)
3. 우선순위가 가장 높은 원소의 제거가 O(lg N)

* 배열로 쉽게 구현하면 시간복잡도가 각각 $O(1)$, $O(N)$, $O(N)$이 되겠지만 힙(Heap)을 사용하면 $O( \lg N)$, $O(1)$, $O( \lg N)$에 처리할 수 있다.
최소 힙에서는 부모가 자식보다 작아야 하고, 최대 힙에서는 부모가 자식보다 커야 한다. 루트가 최소/최대값이 된다.
* 높이가 낮은 곳부터, 높이가 같은 정점은 왼쪽부터 채워나가기 때문에 이진 검색 트리와는 다르게 불균형이 발생하지 않고 늘 균형이 잘 맞는 이진 트리가 된다.
* 삽입 시 reHeapUp, 삭제 시 최소/최대값을 트리 구조 상에서 가장 마지막 위치의 원소와 바꾸고 reHeapDown

> 💥 STL `priority_queue`는 최대 힙, 즉 가장 뒤의 원소를 높은 우선순위로 두는 STL이다. 💥

## STL priority_queue
* 원소 추가 $O(lg N)$
* 우선순위가 가장 높은 원소 확인 $O(1)$
* 우선순위가 가장 높은 원소 제거 $O(lg N)$
* 💥 `priority_queue`는 `set`보다 수행 속도가 빠르고, 공간도 적게 차지한다.
```cpp
int arr[] = {1, 2, 3, 4};
priority_queue<int> pq;  // 기본적으로 최대 힙이 됩니다. 💥
priority_queue<int> pq(arr, arr+4);  // 이 경우에는 vector와 다르게, 1, 2, 3, 4의 순서로 저장된다는 점에 주의합시다. (4가 top()입니다.)
while(!pq.empty()) {
  cout << pq.top() << " ";  // 4, 3, 2, 1로 출력이 되겠죠. queue의 front() 역할을 pq에선 top()이 해 준다는 점에 주의합시다.
  pq.pop();
}
​
priority_queue <int, vector<int>, greater<int>> pq;  // 이 경우에는 4, 3, 2, 1(top)의 순서로 저장됨.
```
___
* priority_queue에서 비교함수를 사용할 때는 그냥 쓰면 안되고 클래스를 만들어서 사용해야 함. ​('23. 4. 5. class뿐만 아니라 struct도 되는 것 같다. [2056 : 작업](https://boj.kr/2056)에서 써먹었음.)
```cpp
class cmp {
public:
  bool operator() (int a, int b) {
    if(abs(a) != abs(b))  return abs(a) > abs(b);
    return a > 0 && b < 0;
  }
};
```
* 👀 이 때 알아야 할 점은, `return a > b` 일 때, `b`가 `top`쪽으로 정렬이 된다는 점이다.