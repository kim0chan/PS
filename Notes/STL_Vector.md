# C++ STL Vector
```cpp
#include <vector>
```

## 벡터의 초기화
```cpp
int N;
vector<int> v(N, 2);
```
이렇게 크기와 초기값을 지정하여 선언할 수 있다.
```cpp
int arr[100];
vector<int> v(arr, arr + 100);
```
이렇게 배열을 복사할 수도 있다.

## 다른 컨테이너 복사
다른 컨테이너를 복사해올 때, 예를 들어
```cpp
unordered_set<string> s;
// ... s에 삽입 삭제 이러쿵저러쿵 ...
vector<string> v(s.begin(), s.end());
```
이렇게 할 수 있다.

심지어
```cpp
unordered_map<string, int> signup;
// ...이러쿵저러쿵...
vector<pair<string, int>> vct(signup.begin(), signup.end())
```
이렇게도 할 수 있다.

## `=`과 deepcopy(깊은 복사)
vector에서 `=`을 사용하면 deepcopy(깊은 복사)가 일어난다.  
\* 반대되는 개념: shallow copy(얕은 복사)
```cpp
vector<int> v3 = {1, 2, 3, 4};    // {1, 2, 3, 4}
v3.erase(v3.begin() + 2);    // {1, 2, 4}
vector<int> v4;    // {  }
v4 = v3;    // {1, 2, 4}
```
이후 v4를 바꿔도 v3에는 영향을 주지 않는다.

## 특정 원소의 삭제(`erase`)
특정 원소를 삭제하기 위해서는 `v.erase` 함수에 `iterator` 범위를 넣어줘야 하는데
이를 위해서 `remove` 함수를 이용한다.  
`remove는` 특정 값을 찾아서 완전히 지우는 것이 아닌, 벡터의 뒤로 보내기 때문에 `erase`와 함께 사용한다.
```cpp
v.erase(remove(v.begin(), v.end(), 지우고 싶은 원소), v.end());​
```

## `vector`의 정렬
```cpp
sort(v.begin(), v.end());
```
이런 식으로 정렬할 수 있고(**기본이 오름차순**​)
```cpp
sort(v.rbegin(), v.rend());
```
역으로 정렬할 수 있다.(**내림차순**)  
아니면 비교함수를 사용하거나 직접 만들어서
```cpp
sort(v.begin(), v.end(), greater<string>()); // 내림차순
```
이런 식으로 쓸 수 있다.

> ### 👀 비교함수를 선언할 땐  
> `compare(앞원소, 뒤원소)` 했을 때 `true`를 반환하도록 해야함.  
> 또한, 같은 수일 때는 무조건 `false`를 반환하도록 해야함. 💥

## 멤버 함수 `size()` 관련 trivia
`size()` 함수는 `unsigned`를 반환한다.  
그래서 integer랑 비교하거나 min-max 함수 통과시킬 때 `int`형으로 형변환 시켜주어야한다.

## `vector`의 최대/최소 원소
최대/최소 원소 찾는 법.  
값이 여러개일 경우 처음 만난 값의 주소를 반환한다!
```cpp
cout << "최댓값은 ?\n";
cout << *max_element(v.begin(), v.end()) << '\n';
​
cout << "최댓값의 idx는 ?\n";
cout << max_element(v.begin(), v.end()) - v.begin() << '\n';
​
cout << "최솟값은 ? \n";
cout << *min_element(v.begin(), v.end()) << '\n';
​
cout << "최솟값의 idx는 ?\n";
cout << min_element(v.begin(), v.end()) - v.begin() << '\n';
```

## `vector` 이분 탐색
```cpp
binary_search(v.begin(), v.end(), 값);
```
찾으려는 값이 있으면 `true`, 없으면 `false`의 `bool` 값을 리턴한다.

## `max_element`와 `min_element` 관련
max_element, min_element는 주소나 이터레이터를 반환함.​

## `upper_bound`와 `lower_bound` 관련
### 💥 일단 정렬을 해야한다.
* `lower_bound`는 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾아줌
* `upper_bound`는 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 찾아줌
* `equal_range`는 (`lower_bound`, `upper_bound`)의 쌍(`std::pair` 객체)을 리턴함

사용법은
```cpp
lower_bound(arr, arr + 6, 6) - arr;
```
이런 식으로 사용하면 된다.  
시작 주소를 빼주는 이유는 인덱스 번호를 반환하게 하기 위함.

> ### ❓ 만약에 찾으려는 key 값이 없으면 어떻게 될까 ?
>    * 배열 끝을 반환함.(예시에선 `arr + 6`)

배열이 정렬되어 있을 때, 값의 개수를 찾아내기 위해서  
upper_bound에서 lower_bound를 빼는 아이디어가 유효하다.

## `vector` 중복 원소 제거법
`unique`는 **연속된 중복 원소**를 벡터 제일 뒷부분으로 쓰레기 값으로 보내버린다.  
즉, **정렬**이 되어있어야 함.
```cpp
v.erase(unique(v.begin(),v.end()),v.end());
```
제껴주면 된다.

#### ('23. 9. 3. 추가)  
`unique()`는 **정렬된 배열**에서 중복이 제거된 원소들을 앞으로 모아주고, 뒤쪽에는 쓰레기 값들을 넣어줌.  
그런 다음 쓰레기 값이 시작되는 구간을 ``return``한다.    
그래서 저렇게 한 줄에 중복 제거를 하는 코드를 작성할 수 있는 것이다.

#### ('23. 10. 17. 추가)
오름차순/내림차순 정렬은 당연히 상관이 없다. 위에도 써 있듯이 연속된 중복 원소를 제거하는 것이기 때문에.  
그래서 `{3, 3, 3, 2, 2, 7, 7, 7, 1, 1, 1, 1}` 같이 대·소가 섞여있는 `vector`의 경우도 성공적으로 중복 제거됨.
​
## `clear()` 함수
```cpp
vector<int> adj;
adj.clear();
```
adj.size()를 0으로 만든다.

## 선언의 차이: `()`와 `[]`
이거 착각 많이 했었는데

#### 🖥ChatGPT의 답변:
* 첫 번째 방법인 `vector<int> vec(320);`은 길이가 320인 벡터를 선언하며, 이 벡터는 메모리의 연속된 공간에 할당됩니다. 이렇게 할당된 벡터는 배열과 유사한 형태로 작동하며, 연속된 메모리 공간으로 인해 캐시 효율이 좋습니다.  
​
* 두 번째 방법인 `vector<int> vec[320];`은 길이가 320인 `vector`의 배열을 선언합니다. 이렇게 선언된 벡터는 메모리의 연속된 공간에 할당되지 않으며, 각 `vector`는 독립적인 메모리 공간을 가지게 됩니다. 이 방법은 각 `vector`가 다른 길이를 가질 수 있으므로 유용할 수 있습니다.​

## vector 2차원 배열 예시
```cpp
// 벡터의 벡터를 선언하기.
vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
```

## 벡터 뒤집기(`reverse`)
```cpp
reverse(v.begin(), v.end());
```
