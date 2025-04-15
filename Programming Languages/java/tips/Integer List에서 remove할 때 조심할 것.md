# `List.remove()`는 두 가지가 있다
```java
List<Integer> list = new ArrayList<>();

list.add(1);
list.add(2);
list.add(3);
```
위 상황에서
### 1. `list.remove(1);`
이건 뭘까?
> 이건 index 1번 요소. 즉 `2`를 제거한다.

📌 **이유**: `remove(int index)`라는 **메서드 오버로딩**이 존재하기 때문!

### 2. `list.remove(Integer.valueOf(1));`
이건?
> 이건 **값이 1인 요소**를 찾아서 제거한다.

📌 **이유**: `remove(Object o)`라는 **다른 메서드 오버로딩**이 존재해서,  
`Integer.valueOf(1)`은 객체니까 이쪽 메서드가 호출된다.