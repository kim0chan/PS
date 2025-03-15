# 배열
# Collections
## List
### `ArrayList`
```java
// 리스트 생성
List<String> list = new ArrayList<>();

// 요소 추가
list.add("Apple");
list.add("Banana");
list.add("Cherry");

// 특정 위치에 요소 추가
list.add(1, "Blueberry"); // ["Apple", "Blueberry", "Banana", "Cherry"]

// 요소 조회
String fruit = list.get(2); // "Banana"

// 요소 삭제
list.remove("Apple");   // "Apple" 삭제
list.remove(1); // 1번 인덱스의 요소 삭제

// 리스트 크기 확인
int size = list.size();

// 리스트 정렬
list.sort(String::compareTo);

// 전체 요소 순회
for (String item : list) {
    System.out.println(item);
}
```
* `set(int index, E e)`
  * 특정 위치 요소 변경
* `indexOf(Object o)`
  * 특정 요소의 인덱스 찾기
* `contains(Object o)`
  * 요소 포함 여부 확인
* `sort(Comparator c)`
  * 정렬

### `LinkedList`
* `LinkedList`는 이중 연결 리스트(Doubly Linked List)를 사용한다.
* 각 노드는 값(value), 이전 노드(prev), 다음 노드(next)를 갖는다.
* 중간 삽입/삭제 시 포인터만 변경하면 되므로 빠르다 (`O(1)`)
* 임의 접근이 느리다 (`O(N)`)
```java
// LinkedList 생성
List <String> list = new LinkedList<>();

// 요소 추가
list.add("Dog")
list.add("Cat")
list.add("Rabbit")

// 첫 번째, 마지막 요소 추가
((LinkedList<String>) list).addFirst("Elephant");
((LinkedList<String>) list).addLast("Horse");

// 요소 조회
String first = ((LinkedList<String>) list).getFirst();
String last = ((LinkedList<String>) list).getLast();

// 요소 삭제
((LinkedList<String>) list).removeFirst();
((LinkedList<String>) list).removeLast();

// 전체 요소 순회
for (String item : list) {
    System.out.println(item);
}
```
* `pollFirst()`
  * 첫 번째 요소 제거 후 반환 (`null` 가능)
  * 마지막 요소 제거 후 반환 (`null` 가능)

> ## `size`와 `length`의 차이
> * `size()`
>   * 컬렉션의 크기를 반환함
>   * `ArrayList`, `LinkedList`, `HashSet`, `HashMap` 같은 컬렉션 프레임워크에 적용
>   * 내부적으로 저장된 요소 개수를 반환함
> * `length()`
>   * 배열(`Array`)이나 문자열(`String`)의 길이를 반환
>   * 배열이 차 있는 개수를 반환함

## Deque
## Set
## Map

# String
