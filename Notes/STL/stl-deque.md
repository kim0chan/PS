# C++ STL deque(덱)
```cpp
#include <deque>
```

## 덱의 성질
1. 원소 추가/제거 $O(1)$
2. 앞/뒤 원소 확인 $O(1)$
3. 앞/뒤가 아닌 원소들의 확인/변경이 원칙적으로 불가능
4. **STL `stack`, `queue` 등에서 불가능했던 인덱스를 이용한 원소 접근이 가능함.**
    * < FRONT ELEM ELEM ... ELEM ... BACK>  <-- 이런 구조로 되어있음.

## 멤버 함수
```cpp
​deque<int> DQ;​
DQ.empty();
DQ.size();
DQ.front();
DQ.back();
DQ.push_back(val);
DQ.push_front(val);
DQ.pop_back();
DQ.pop_front();
```
