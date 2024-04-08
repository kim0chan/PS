# 정렬 Sort
```cpp
#include <algorithm>
```

## Comparison Sort
### $O(N^2)$
* 선택 정렬 (Selection Sort)
* 삽입 정렬 (Insertion Sort)
* 버블 정렬 (Bubble Sort)

### $O(N \lg N)$
* 합병 정렬 (Merge Sort)
  * 추가적인 공간이 필요하다. (In-Place Sort가 아니다.)
  * Stable Sort이다.
* 퀵 정렬 (Quick Sort)
  * 제일 빠르다.
  * In-Place Sort가 아니기 때문에 Cache Hit Rate가 높음.
  * Stable하지 않다.
  * 💥 최악의 경우 O(N^2)이다.

## Non-comparison Sort
### $O(N+K)$
* 계수 정렬 (Counting Sort)
  * 수의 범위 K가 커지면 공간복잡도가 매우 커진다
  * 하지만 trade-off
### $O(D(N+K))$
* 기수 정렬 (Radix Sort)

> ### Stable Sort란?
> * 우선순위가 같은 원소가 여러 개 존재할 때, 정렬 결과는 유일하지 않을 수 있다.
> * 우선순위가 같은 원소들끼리 정렬 후에도 원래의 순서를 유지하도록 하는 정렬을 Stable Sort라고 한다.

## C++ STL Sort
```cpp
// `array`에서의 sort
int a[5] = {1, 4, 5, 2, 7};
sort(a, a+5);
```
```cpp
// `vector`에서의 sort
vector<int> b = {1, 4, 5, 2, 7};
sort(b.begin(), b.end());    // b.end() == b.begin() + 5
```
```cpp
// 정렬 순서 Customization
bool cmp(int a, int b) {    // a가 b의 앞에 와야할 때 true, 그렇지 않을 때 false
    if(a%5 != b%5) return a%5 < b%5;
    return a < b;
}
// 💥 두 값이 같을 때 혹은 우선순위가 같을 때는
// 반드시 `false`를 반환해야 한다.
​
int a[7] = {1, 2, 3, 4, 5, 6, 7};
sort(a, a+7, cmp);
```
```cpp
// 💥 비교 함수의 인자로 STL 혹은 클래스 객체를 전달 시에 reference를 사용한다.
bool cmp(const string& a, const string& b) {
    return a.back() < b.back();
}
```
```cpp
// 역순으로 정렬하기
sort(a.begin(), a.end(), greater<>());
sort(v.rbegin(), v.rend());
```
> 💡 pair<int, int>형의 경우 일단 .first를 기준으로 정렬되고, .first가 같은 개체에 대해서는 .second를 기준으로 다시 정렬된다!

## 문제 풀이 꿀팁
* 오름차순(및 비내림차순 뭐 이런 것들)으로 주어진 수들을 정렬할 때 N이 엄청나게 크다면 계수 정렬(Counting Sort)을 이용하면 좋다.
  * 각 수 별로 등장 횟수를 저장한 뒤 배열을 순회하며 등장 횟수만큼 출력해 주는 알고리즘이다.
  * 💥 단, 수의 범위가 자연수 인지 등을 확인해야 한다. 음수를 포함한다면 인덱스 오류가 발생하므로 ...  
  (참고 : [10989] 수 정렬하기 3)
* 등장 횟수가 가장 많은 원소를 출력하는 것도 정렬을 해서 카운트하는 방식으로 풀어낼 수 있다.  
  (참고 : [11652] 카드)
​