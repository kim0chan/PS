# 수학 Mathematics
```cpp
#include <cmath>
```

## 소수 Prime Number
* 1과 자기 자신으로만 나누어지는 수
* 약수가 2개인 수
* 2부터 N-1까지의 수로 나누어지지 않는 수
> 합성수에서 N에서 1을 제외한 가장 작은 약수는 √N 이하이다.  
즉, 2부터 √N까지의 수로 나누어지지 않으면 소수이다.
```cpp
// 소수 판별 알고리즘
bool isPrime(int n) {
  if(n == 1) return false;
  for(int i = 2; i*i <= n; i++) {
    if(n % i == 0) return false;
  }
  return true;
}
```

## 에라토스테네스의 체
* 골드바흐의 추측을 사용하는 전략
* PS 문제 범위 정도에 대해서는 모든 짝수가 두 소수의 합으로 표현된다고 알려져 있으므로 해당 사실을 이용하기
```cpp
vector<bool> state(1000001, true);    // 기본적으로 true로 초기화해준다.
​
void sieve(int n) {
  state[1] = false;
  for(int i = 2; i*i <= n; i++) {
    if(!state[i]) continue;
    for(int j = i*i; j <= n; j += i)
      state[j] = false;
  }
}
​
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  seive(n);
  for(int i = m; i <= n; i++) {
    if(state[i]) cout << i << '\n';
  }
}
```

## 최대공약수 Great Common Divisor, GCD
* 두 자연수의 공통된 약수 중 가장 큰 약수

### 유클리드 호제법
* 두 수 `A`, `B`에 대해 `A`를 `B`로 나눈 나머지를 `r`이라고 하면 `GCD(A, B)` = `GCD(B, r)`이다.
```cpp
int gcd(int a, int b) {
  if(a == 0) return b;
  return gcd(b%a, a);
}
```

## 최소공배수 Least Common Multiple, LCM
* $A \times B = GCD(A,B) \times LCM(A,B)$
  * 여기서 $LCM(A,B)$은 구할 수 있죠?
```cpp
int lcm(int a, int b) {
  return a / gcd(a, b) * b;    // int overflow를 방지
}
```

## 소인수분해 Factorization
```cpp
vector<int> solve;
​
int main(void) {
  int N;
  ​​cin >> N;
  ​
  for (int i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      solve.push_back(i);
      N /= i;
    }
  }
  ​
  for (auto a : solve) {
    cout << a << '\n';
  }
​
  if (N != 1) cout << N << '\n';
}
```

## C++의 `<cmath>`
### 올림, 내림, 반올림
* 소수점 둘째 자리까지 반올림하려면 어떻게 할까?
  * `<cmath>`의 `floor()` 함수는 내림 함수이고, `ceil()` 함수는 올림 함수이다.
    ```cpp
    double a = 3.14159;
    cout << floor((a * 1e2) + 0.5) / 1e2;
    ```
  * 순서에 유의하도록 하자.
    * 헷갈린다면 소숫점이 어떻게 움직이는지, 최종 값이 어떻게 계산될지를 머릿속에 그려보면 된다.

### 제곱
```cpp
pow(x, y);    // x ^ y 값을 반환한다.
exp(x);    // e ^ x 값을 반환한다.
sqrt(x);    // x의 제곱근을 반환한다.
```

### 로그
```cpp
log(x);    // 자연로그 값 ln(x)를 반환한다.
log10(x);    // 밑이 10인 상용로그 값을 반환한다.
```
