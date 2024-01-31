# C++ STL unordered set and map (해시)
```cpp
#include <unordered_set>
#include <unordered_map>
```
## Key와 Value
```cpp
unordered_map<string, int> um;
```
안에 들어있는 원소의 `.first`는 key고 `.second`는 value가 된다.

## 다른 컨테이너 복사
```cpp
unordered_set<string> s;
// ... `s`에 삽입 삭제 이러쿵저러쿵
vector<string> v(s.begin(), s.end());
```
이렇게 할 수 있다.  
심지어는
```cpp
unordered_map<string, int> signup;
// ... 이러쿵저러쿵
vector<pair<string, int>> vct(signup.begin(), signup.end());
```
이렇게 빌려올 수도 있다.

## `size()` 멤버 함수 trivia
`.size()` 함수는 `unsigned int`를 반환한다.  
그래서 integer랑 비교하거나 `min`, `max` 함수 통과시킬 때 `int`형으로 형변환 시켜주어야 함.