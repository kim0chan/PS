# C++ STL unordered set and map (해시)
```cpp
#include <unordered_set>
#include <unordered_map>
```
## 해시 함수
* 임의 길이의 데이터를 고정된 길이의 데이터로 대응시키는 함수
* 해시 자료구조란?
    * 키를 배열의 인덱스로 보내는 해시 함수를 하나 둬서 테이블로 관리를 하는 것
        * $O(1)$에 연산 가능

## 충돌 회피
0. 충돌이란?
    * 서로 다른 키가 같은 해시 값을 가지게 되는 경우
    * 기본적으로 해시 함수를 통해서 함수 입력으로 주어지는 정의역의 공간을 압축시키는 것이기 때문에 발생할 수 있다.
    * 각 키의 해시 값이 최대한 균등하게 퍼져야 성능이 좋아지므로 주어진 데이터에 대한 좋은 해시 함수를 정해야한다.
1. 회피: Chaining
    * 각 인덱스마다 연결 리스트를 둔다.
    * 이상적인 상황에서는 $O(1)$이지만 모든 키의 해시 값이 같은 최악의 상황에서는 $O(N)$
1. 회피: Open Addressing
    * 인덱스에 바로 (키, 값) 쌍을 쓴다.
    * insert시에 충돌이 발생하면 인접한 인덱스에 내용을 쓴다.
    * find시에는 연결된 인덱스를 모두 확인한다.
    * erase시에는 쓰레기 값을 두어서 데이터가 삭제되었음을 표시해야한다.
        * 이렇게 인접한 영역을 확인하는 것을 Linear Probing이라고 한다. Cache Hit Rate가 높다.
            * 그러나 Clustering(데이터 차있는 영역이 뭉쳐있는 것. 군집)이 발생하게 되고 이 Cluster가 커지면 커질수록 인덱스가 군집에 걸렸을 때 빈 칸을 찾을 때까지 이동해야 하는 횟수가 늘어나서 성능이 저하된다.
        * Quadratic Probing은 충돌이 발생하면 오른쪽으로 1, 3, 5, ...칸 이동한다. 처음 위치를 기준으로는 1, 4, 9, ...(제곱수)칸 이동하는 것이다.
            * Clustering을 어느 정도 회피할 수 있고 Cache Hit Rate도 나쁘지는 않다. 다만 해시 값이 같다면(시작점이 같으므로) 똑같은 경로를 따라가기 때문에 여전히 Clustering이 발생한다.
        * Double Hashing은 해시 함수를 하나 더 둬서 충돌이 발생했을 때 몇 칸 점프할지를 새로운 해시 함수로 계산하는 방식이다
            * Clustering을 효과적으로 회피할 수 있지만 Cache Hit Rate가 안좋아진다.

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