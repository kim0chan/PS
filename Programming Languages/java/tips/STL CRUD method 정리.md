# `Stack`
### Create
- `push(E e)`
### Read
- `peek()`
### ~~Update~~
### Delete
- `pop()`
# `Queue`
### Create
- `offer(E e)`
### Read
- `peek(E e)`
### ~~Update~~
### Delete
- `poll()`
# `ArrayList`
### Create
- `add(E e)`
- `add(int index, E e)`
### Read
- `get(int index)`
### Update
- `set(int index, E e)`
### Delete
- `remove(int index)`

| 메서드                   | 설명             |
| --------------------- | -------------- |
| `add(E e)`            | 요소 추가          |
| `add(int index, E e)` | 특정 위치에 요소 삽입   |
| `get(int index)`      | 요소 조회          |
| `remove(int index)`   | 특정 위치 요소 삭제    |
| `remove(Object o)`    | 특정 값을 가진 요소 삭제 |
| `set(int index, E e)` | 특정 위치의 요소 변경   |
| `indexOf(Object o)`   | 특정 요소의 인덱스 찾기  |
| `contains(Object o)`  | 요소 포함 여부 확인    |
| `sort(Comparator c)`  | 정렬             |
# `ArrayDeque`
### Create
- `offerFirst(E e)`
- `offerLast(E e)`
### Read
- `peekFirst()`
- `peekLast()`
### ~~Update~~
### Delete
- `pollFirst()`
- `pollLast()`

| 메서드               | 설명           |
| ----------------- | ------------ |
| `offerFirst(E e)` | 앞에 요소 추가     |
| `offerLast(E e)`  | 뒤에 요소 추가     |
| `pollFirst()`     | 앞 요소 제거하며 반환 |
| `pollLast()`      | 뒤 요소 제거하며 반환 |
| `peekFirst()`     | 앞 요소 조회      |
| `peekLast()`      | 뒤 요소 조회      |
