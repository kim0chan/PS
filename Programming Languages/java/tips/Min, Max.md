# 1. `Math` 클래스 사용 (기본 타입)
```java
int a = 5, b = 10;

int min = Math.min(a, b);  // 5
int max = Math.max(a, b);  // 10
```
- 자료형 지원: `int`, `long`, `float`, `double`
# 2. 배열 또는 리스트에서 Min/Max 구하기
### 배열
```java
int[] arr = { 3, 7, 2, 9, 5 };

int min = Arrays.stream(arr).min().getAsInt();
int max = Arrays.stream(arr).max().getAsInt();
```
### 리스트
```java
List<Integer> list = Arrays.asList(3, 7, 2, 9, 5);

int min = Collections.min(list);
int max = Collections.max(list);
```
### Optional 값 처리 (Stream 사용 시)
```java
OptionalInt optMin = Arrays.stream(arr).min();
if (optMin.isPresent()) {
	int min = optMin.getAsInt();
}
```
### Comparator로 객체 리스트에서 Min/Max 구하기
```java
List<Person> people = ...;

Person youngest = Collections.min(perople, Comparator.comparing(Person::getAge));
Person oldest = Collections.max(people, Comparator.comparing(Person::getAge));
```
## ✅ 요약 표

|상황|메서드 예시|
|---|---|
|기본 숫자 2개|`Math.min(a, b)` / `Math.max(a, b)`|
|배열|`Arrays.stream(arr).min().getAsInt()`|
|리스트 (`List<Integer>`)|`Collections.min(list)` / `max(list)`|
|객체 리스트|`Collections.min(list, Comparator)`|