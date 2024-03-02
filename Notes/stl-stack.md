# C++ STL stack(스택)
```cpp
#include <stack>
// ...
stack<int> st;
```

## 스택의 성질
1. 원소의 추가/제거 $O(1)$
2. 최상단 원소 확인 $O(1)$
3. 상단이 아닌 원소들의 확인/변경 불가능

## 멤버 함수
```cpp
st.empty();
st.size();
st.top();
st.push(val);
st.pop();
```
