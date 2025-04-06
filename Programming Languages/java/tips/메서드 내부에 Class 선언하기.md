```java
public int solution() {
	// 메서드 내부에 Pair 클래스 선언 (로컬 클래스)
	class Pair {
		int first, second;
		
		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
}
```
-  💥로컬 클래스는 `static` 키워드를 사용할 수 없다.
	- (메서드 내부에서는 정적 클래스로 선언할 수 없다.)
	- 즉 메서드 내부에서 선언한 `Pair`는 외부 클래스의 인스턴스 없이 사용할 수 없다.
## 메서드 내부 로컬 클래스의 `ArrayList` 정렬하기
- 로컬 클래스를 사용한 `ArrayList`는 일반적인 클래스와 동일하게 `Collections.sort()` 또는 `List.sort()`를 이용해서 정렬할 수 있다.
### 1️⃣ `Comparable`을 구현하기
```java
public void solution() {
	class Pair implements Comparable<Pair> {
		int first, second;
		
		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
		
		@Override
		public int compareTo(Pair o) {
			return Integer.compare(this.first, o.first)  // `first` 기준 오름차순 정렬
		}
		
		List<Pair> list = new ArrayList<>();
		list.add(new Pair(3, 10));
		list.add(new Pair(1, 20));
		list.add(new Pair(2, 15));
		
		Collections.sort(list);
	}
}
```
### 2️⃣ `Comparator`를 사용하여 정렬 기준 변경하기 (★)
```java
public void solution() {
	class Pair {
		int first, second;

		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}

	List<Pair> list = new ArrayList<>();
	list.add(new Pair(3, 10));
	list.add(new Pair(1, 20));
	list.add(new Pair(2, 15));

	// first 기준 오름차순 정렬
	list.sort(Comparator.comparingInt(p -> p.first));
	System.out.println(list); // 출력: [(1, 20), (2, 15), (3, 10)]

	// second 기준 내림차순 정렬
	list.sort((a, b) -> Integer.compare(b.second, a.second));
	System.out.println(list); // 출력: [(1, 20), (2, 15), (3, 10)]
}
```
