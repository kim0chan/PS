# `list.sort()`와 `Collections.sort(list)`의 차이점
| 메서드                                  | 정의된 곳                  | 사용가능 대상                     | 내부 정렬 방식                                  | 필요 조건                   |
| ------------------------------------ | ---------------------- | --------------------------- | ----------------------------------------- | ----------------------- |
| `list.sort(comparator)`              | `List` 인터페이스           | `ArrayList`, `LinkedList` 등 | `List`의 `sort()` 메서드                      | `List` 객체               |
| `Collections.sort(list, comparator)` | `Collections` 유틸리티 클래스 | `List` 인터페이스 구현체            | `Arrays.sort()` 호출 (Dual-pivot QuickSort) | `List` 객체 (nullable 가능) |
## 1️⃣ `list.sort()`
```java
List<Integer> list = Arrays.asList(3, 1, 4, 1, 5, 9);
list.sort(Comparator.naturalOrder());
System.out.println(list);  // [1, 1, 3, 4, 5, 9]
```
- `List` 내부에서 정렬 실행 -> `Comparator`가 필요함
# 2️⃣ `Collections.sort()`
```java
List<Integer> list = Arrays.asList(3, 1, 4, 1, 5, 9);
Collections.sort(list);
System.out.println(list);  // [1, 1, 3, 4, 5, 9]
```
- 내부적으로 `list.sort(null)`을 호출 (`list.sort(Comparator.naturalOrder())`와 동일)
- `null`이 들어가도 동작 가능