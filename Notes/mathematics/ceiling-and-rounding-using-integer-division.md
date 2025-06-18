# 올림 공식
어떤 수 $n$을 $m$으로 나눌 때 올림(ceil) 하는 것은 다음 식으로 표현할 수 있다.  
$$⌈\frac{m}{n}​⌉=⌊\frac{n+(m−1)}{m}​⌋$$
## 예시
$n = 11$, $m = 5$
$$⌈\frac{11}{5}⌋=3$$
일 때,
$$⌊\frac{11+4}{5}​⌋ = ⌊\frac{15}{5}⌋ = 3$$
즉, 동일한 결과를 얻을 수 있다.
## 실전 활용
프로그래밍 언어의 정수 나눗셈에서 올림을 직접 지원하지 않기 때문에, 다음과 같은 방식을 쓸 수 있다.
```java
// Java
int ceilDiv = (n + m - 1) / m;
```
# 반올림 공식
어떤 정수 $n$을 정수 $m$으로 반올림 나눗셈 하려면 다음 공식을 사용한다.
$$⌊\frac{n + \frac{m}{2}}{m}⌋(단, m>0)$$
## 실전 활용
위 식을 정수 연산으로 표현하면 다음과 같다.
```java
// Java
int result = (n + m / 2) / m;
```
___

> [!warning] 음수일 때는 주의
> 음수는 보정이 필요하다.

## 음수를 고려한 올림
```java
int floorDiv = (n >= 0) ? (n / m) : ((n - m + 1) / m);

// 혹은 내장 함수를 사용할 수 있다.
int floorDiv = Math.floorDiv(n, m);
```
## 음수를 고려한 반올림
```java
int roundDiv(int n, int m) {
    if (n >= 0) {
        return (n + m / 2) / m;
    } else {
        return (n - m / 2) / m;
    }
}
```