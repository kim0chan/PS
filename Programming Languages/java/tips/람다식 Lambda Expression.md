람다식은 익명 함수(anonymous function)를 생성하는 문법이다.  
기존의 클래스 or 익명 클래스를 생성하지 않고도 함수를 간단하게 표현할 수 있다.
# 1️⃣ 기본 문법
기본 형태:
```java
(매개변수) -> { 실행 코드 }
```
- 매개변수가 1개면 괄호 `()` 생략 가능
- 실행 코드가 1줄이면 `{}` 생략 가능
```java
// 매개 변수가 1개일 때 -> 괄호 생략 가능
x -> x * x

// 매개 변수가 2개 -> 괄호 필수
(x, y) -> x + y

// 실행 코드가 여러 줄 -> {} 사용
(x, y) -> {
	int sum = x + y;
	return sum;
}
```
# 2️⃣ `Function<T, R>`을 사용한 람다식
```java
import java.util.function.Function;

public class Main {
	public static void main(String[] args) {
		Function<Integer, Integer> square = x -> x * x;
		System.out.println(square.apply(5));  // 출력: 25
	}
}
```
- `Function<T, R>`: 입력 `T`를 받아 `R`을 반환하는 함수형 인터페이스
- `apply(값)`을 호출해서 실행 가능