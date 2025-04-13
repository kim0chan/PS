# 배열
## 선언 및 생성
```java  
int[] arr1 = new int[5];  
int arr2[] = new int[5];    // C-Style  
int[] arr3 = {1, 2, 3, 4, 5};   // 선언과 동시에 초기값 지정  
int[] arr4 = new int[]{1, 2, 3, 4, 5};  // `new` 키워드로 명시적 초기화  
```  
## 2차원 배열
```java  
int[][] matrix = {  
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
};  
  
int[][] matrix2 = new int[3][3];  
```  
## 배열 정렬 (`Arrays.sort()`)
```java  
import java.util.Arrays;  
  
public class Main {  
    public static void main(String[] args) {
    int[] arr = {5, 2, 8, 1, 3};
    Arrays.sort(arr);  // 오름차순 정렬  
    System.out.println(Arrays.toString(arr)); // 출력: [1, 2, 3, 5, 8]  
}}  
```
### 💡비교 함수 넘겨서 커스터마이징하기
정렬할 때 비교 함수(Comparator)를 전달해 정렬 기준을 마음대로 설정할 수 있다.
##### ✅ 기본 문법
```java
Arrays.sort(array, comparator);
```
##### 예시 (`String[]`) 내림차순 정렬
```java
String[] arr = {"aa", "e", "abc", "zzz"};

Arrays.sort(arr, (a, b) -> b.compareTo(a));
```
##### ✅ 원하는 순서 만들기
Comparator는 다음 구조를 따른다.
```java
(a, b) -> {
	return 음수;  // a < b (a가 앞)
	return 양수;  // a > b (b가 앞)
	return 0;    // 같음
}
```


## 배열 복사 (`Arrays.copyOf()`)
```java  
int[] original = {1, 2, 3};  
int[] copy = Arrays.copyOf(original, 5);  // 크기 5짜리 복사본 생성  
System.out.println(Arrays.toString(copy));  // 출력: [1, 2, 3, 0, 0]  
```  
> ☝️ Wrapper Class는 Reference Type이라 기본 값이 `null`로 초기화되고,  
> Primitive Type은 `false`, `0`등으로 초기화가 된다.
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
List<String> list = new LinkedList<>();  
  
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
    >   * **컬렉션**의 크기를 반환함
    >   * `ArrayList`, `LinkedList`, `HashSet`, `HashMap` 같은 컬렉션 프레임워크에 적용
>   * 내부적으로 저장된 요소 개수를 반환함
> * `length()`
    >   * 문자열(`String`)의 길이를 반환
    >   * 배열이 차 있는 개수를 반환함
> * `length`
    >   * Array의 길이 반환

## Deque
* Double-Ended Queue
  * 앞(`front`)과 뒤(`rear`)에서 삽입/삭제 가능
  * `Queue`처럼 앞에서 빼거나(`pollFirst()`), `Stack`처럼 뒤에서 뺄 수도 있음(`pollLast()`)
  * `Deque`는 `Queue`의 확장 인터페이스
  * `ArrayDeque`, `LinkedList`는 `Deque`를 구현하는 클래스
* 요소 삽입
  * `addFirst(E e)`
    * 앞에 요소 추가 (예외 발생 가능)
  * `addLast(E e)`
    * 뒤에 요소 추가 (예외 발생 가능)
  * `offerFirst(E e)`
    * 앞에 요소 추가 (`true` 반환, 실패 시 `false`)
  * `offerLast(E e)`
    * 뒤에 요소 추가 (`true` 반환, 실패 시 `false`)
* 요소 제거
  * `removeFirst()`
    * 앞 요소 제거 (예외 발생 가능)
  * `removeLast()`
    * 뒤 요소 제거 (예외 발생 가능)
  * `pollFirst()`
    * 앞 요소 제거 (비어있으면 `null` 반환)
  * `pollLast()`
    * 뒤 요소 제거 (비어있으면 `null` 반환)
* 요소 조회
  * `getFirst()`
    * 앞 요소 조회 (예외 발생 가능)
  * `getLast()`
    * 뒤 요소 조회 (예외 발생 가능)
  * `peekFirst()`
    * 앞 요소 조회 (비어있으면 `null` 반환)
  * `peekLast()`
    * 뒤 요소 조회 (비어있으면 `null` 반환)
* `Deque`를 `Stack`처럼 사용 (LIFO)
```java  
import java.util.Deque;  
import java.util.ArrayDeque;  
  
public class Main {  
    public static void main(String[] args) {
    Deque<String> stack = new ArrayDeque<>();
    
	// push() 대신 addFirst() 사용 가능  
	stack.push("A");
	stack.push("B");
	stack.push("C");
    
    // pop()으로 첫 번째 요소 제거 (LIFO)
    System.out.println(stack.pop()); // 출력: "C"  
	System.out.println(stack.pop()); // 출력: "B"  
    }
}  
```  
* `Deque`를 `Queue`처럼 사용 (FIFO)
```java  
import java.util.Deque;  
import java.util.ArrayDeque;  
  
public class Main {  
    public static void main(String[] args) {
    Deque<String> queue = new ArrayDeque<>();  
    
        // offer() 대신 addLast() 사용 가능  
        queue.offer("A");
        queue.offer("B");
        queue.offer("C");
        
        // poll()으로 첫 번째 요소 제거 (FIFO)
        System.out.println(queue.poll()); // 출력: "A"  
        System.out.println(queue.poll()); // 출력: "B"  
    }
}  
```  

## Set
`Set`은 중복을 허용하지 않는 컬렉션이다.    
배열이나 리스트와 달리 중복된 값을 저장할 수 있어서, 유일한 값들이 필요한 경우 사용한다.
### `HashSet`
```java  
import java.util.HashSet;  
  
public class Main {  
    public static void main(String[] args) {
    HashSet<Integer> set = new HashSet<>();
    
    set.add(10);
    set.add(20);
	set.add(30);
	set.add(10);  // 중복 값 추가 시 무시됨  
  
    System.out.println(set);  // 출력: [20, 10, 30] (순서 보장 X)
    }
}  
```  
* 💡 중복된 값은 저장되지 않는다.
* 💡 삽입 순서를 보장하지 않으므로 주의한다.
  * `LinkedHashSet`은 `HashSet`과 거의 같지만 입력한 순서를 유지한다.

#### `HashSet` 주요 메서드
```java  
set.add(40);         // 요소 추가  
set.remove(20);      // 특정 요소 제거  
set.contains(10);    // 특정 요소 포함 여부 확인 (true / false)
set.size();          // Set의 크기 반환  
set.isEmpty();       // Set이 비어있는지 확인  
set.clear();         // 모든 요소 제거  
```  

## Map
Key-Value 쌍을 저장하는 자료구조
### `HashMap`
```java  
import java.util.HashMap;  
  
public class Main {  
    public static void main(String[] args) {
    HashMap<String, Integer> map = new HashMap<>();
    
    map.put("apple", 3);
    map.put("banana", 5);
    map.put("cherry", 2);  
    
    System.out.println(map.get("banana"));  // 출력: 5  
    System.out.println(map);  // 출력: {banana=5, cherry=2, apple=3} (순서 보장 X)
    }
}
```  
* Key는 중복될 수 없지만, Value는 중복될 수 있다.
* 순서는 보장되지 않는다.

#### `HashMap` 주요 메서드
```java  
map.put("orange", 7);  // 요소 추가  
map.get("banana");     // 키를 이용해 요소 조회  
map.remove("apple");    // 키를 이용해 요소 삭제  
map.containsKey("banana");  // 특정 키 포함 여부 확인 (true / false)
map.containsValue(2);   // 특정 값 포함 여부 확인 (true / false)
map.size();  // Map의 크기 반환  
map.isEmpty();          // 비어있는지 확인  
map.clear();            // 모든 요소 삭제  
```  
#### 반복문 순회
```java  
for (String key : map.keySet()) {  
    System.out.println(key + " => " + map.get(key));
}  
```  
* 💡 `keySet()`을 사용하면 모든 Key를 가져올 수 있다.

### `LinkedHashMap`
`HashMap` 과 기능은 동일하지만 입력한 순서를 유지한다.
#### (부록) Collection (`List`)의 정렬
- `Collections.sort()`를 이용한다.
```java
List<Integer> list = Arrays.asList(1, 3, 5, 7, 9);
Collections.sort(list);
```

# 🔺String
## 주요 메서드
* 문자열 길이 확인
```java  
String str = "Java Programming";  
System.out.println(str.length());  // 출력: 16  
```  
* 문자열 비교
```java  
String s1 = "hello";  
String s2 = "hello";  
String s3 = new String("hello");  
  
System.out.println(s1.equals(s2));  // true (내용 비교)  
System.out.println(s1.equals(s3));  // true (내용 비교)  
System.out.println(s1 == s3);       // false (객체 비교)  
  
System.out.println("Java".equalsIgnoreCase("java"));  // true (대소문자 무시)  
```  
* 문자열 찾기 (`indexOf`, `contains`)
```java  
String str = "Hello, Java!";  
System.out.println(str.indexOf("Java"));  // 출력: 7  
System.out.println(str.indexOf("Python")); // 출력: -1 (없으면 -1)
System.out.println(str.contains("Java")); // true (포함 여부)  
```  
* 문자열 자르기 (`substring`)
```java  
String str = "Hello, Java!";  
System.out.println(str.substring(7));    // 출력: Java!  
System.out.println(str.substring(7, 11)); // 출력: Java (끝 인덱스는 포함 안됨)  
```  
> 💡 `substring(start, end)` → `start`부터 `end-1`까지
* 문자열 치환 (`replace`, `replaceAll`)
```java  
String str = "Java is fun!";  
System.out.println(str.replace("Java", "Python")); // 출력: Python is fun!  
System.out.println(str.replaceAll("\\s", "-"));    // 출력: Java-is-fun! (모든 공백을 -로 변경)  
```  
* 💡 `replace()`는 단순 치환, `replaceAll()`은 정규식 사용 가능
* 문자열 분리 (`split`)
```java  
String str = "apple,banana,orange";  
String[] arr = str.split(",");  
  
for (String s : arr) {  
    System.out.println(s);
}  
```  
* 문자열 공백 제거 (`trim`, `strip`)
```java  
String str = "  Java  ";  
System.out.println("[" + str.trim() + "]");  // [Java] (양쪽 공백 제거)  
System.out.println("[" + str.strip() + "]"); // [Java] (Java 11부터 도입)  
```  
* 💡 `trim()`은 양쪽 공백 제거, `strip()`은 유니코드 공백도 처리 가능 (Java 11 이상)
* 대소문자 변환 (`toUpperCase`, `toLowerCase`)
```java  
String str = "Java";  
System.out.println(str.toUpperCase()); // JAVA  
System.out.println(str.toLowerCase()); // java  
```  
* 문자열 조합 (`concat`, `join`)
```java  
String str1 = "Hello";  
String str2 = "Java";  
System.out.println(str1.concat(", ").concat(str2)); // Hello, Java  
  
String result = String.join("-", "apple", "banana", "cherry");  
System.out.println(result); // apple-banana-cherry  
```
### 💡 문자를 붙여나가는 작업이 반복적일 경우
-> `StringBuilder`를 사용하는 것이 효율적이다.
```java
String buildString(String[] words) {
	StringBuilder sb = new StringBuilder();

	for (String word : words) {
		sb.append(word);
	}

	return sb.toString();
}
```
만약 **한 글자만** 앞에만 붙여나간다면 `sb.insert(0, word)` 처럼 할 수 있지만, 이는 비효율적이므로 `reverse`를 이용하자.
```java
String buildReversedString(String[] words) {
	StringBuilder sb = new StringBuilder();

	for (String word : words) {
		sb.append(word);
	}

	return sb.reverse().toString();
}
```
순서를 다르게 할거면 words부터 뒤집으면 된다. (Array라면 index 순서를 꼬고, Collections라면 `Collections.reverse()`를 쓰자.)
# PriorityQueue
- Java에서 `PriorityQueue`는 우선순위 큐를 구현하는 클래스
- 기본적으로 **작은 값이 우선순위가 높음 (최소 힙)**
- 최대 힙으로 만들려면 `Comparator`를 사용해야 한다.
```java
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) {
		PriorityQueue<Integer> pq = new PriorityQueue<>();  // 기본: 최소 힙
		pq.add(5);
		pq.add(1);
		pq.add(3);
		
		System.out.println(pq.poll());  // 1
		System.out.println(pq.poll());  // 3
		System.out.println(pq.poll());  // 5
	}
}
```
- 자동 정렬됨 (오름차순 정렬)
- `add()` / `offer()`: 요소 추가
- `poll()`: 최우선순위 요소 제거 후 반환
- `peek()`: 최우선순위 요소 확인 (제거 X)
## 최대 힙 만들기 (내림차순)
```java
PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
maxHeap.add(5);
maxHeap.add(1);
maxHeap.add(3);

System.out.println(maxHeap.poll());  // 5
System.out.println(maxHeap.poll());  // 3
System.out.println(maxHeap.poll());  // 1
```
- `Comparator`를 사용해서 내림차순 정렬
- 큰 값이 먼저 나오도록 변경
## 커스텀 객체 정렬 (Comparator 활용)
```java
class Job {
	int id, priority;
	
	public Job(int id, int priority) {
		this.id = id;
		this.priority = priority;
	}
	
	@Override
	public String toString() {
		return "Job{id=" + id + ", priority=" + priority + "}";
	}
}

public class Main {
	public static void main(string[] args) {
		PriorityQueue<Job> jobQueue = new PriorityQueue<>(Comparator.comparingInt(j -> j.priority));
		
		jobQueue.add(new Job(1, 3));
		jobQueue.add(new Job(2, 1));
		jobQueue.add(new Job(3, 2));
		
		while (!jobQueue.isEmpty()) {
			System.out.println(jobQueue.poll());
		}
	}
}
```

| 메서드                       | 설명                 |
| ------------------------- | ------------------ |
| `add(E e)` / `offer(E e)` | 요소 추가              |
| `poll()`                  | 최우선순위 요소 제거 후 반환   |
| `peek()`                  | 최우선순위 요소 확인 (제거 X) |
| `size()`                  | 현재 요소 개수 반환        |
| `isEmpty()`               | 큐가 비었는지 확인         |
