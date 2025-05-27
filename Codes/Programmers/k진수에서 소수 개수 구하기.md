## 핵심 아이디어
- K진수 변환
- `"0"`으로 `split`하기 (자동으로 "0" 포함하는 candidate 제거됨)
- 에라토스테네스의 체, 소수 판별 알고리즘 사용하여 count하기
## Java Code - 에라토스테네스의 체 이용
```java
import java.util.*;

class Solution {
    private static final int MAX = 1_000_001;

    public int solution(int n, int k) {
        boolean[] sieve = buildSieve(MAX);
        String converted = convertBase(n, k);
        String[] tokens = converted.split("0");

        int count = 0;
        for (String token : tokens) {
            if (token.isEmpty() || token.contains("0")) continue;

            long number = Long.parseLong(token);
            if (number < (long) MAX) {
                if (sieve[(int) number])    count++;
            } else {
                if (isPrime(number))        count++;
            }
        }

        return count;
    }

    // 에라토스테네스의 체 생성
    private boolean[] buildSieve(int limit) {
        boolean[] sieve = new boolean[limit];
        Arrays.fill(sieve, true);
        sieve[0] = sieve[1] = false;

        for (int i = 2; i * i < limit; i++) {
            if (!sieve[i]) continue;
            for (int j = i * i; j < limit; j += i) {
                sieve[j] = false;
            }
        }

        return sieve;
    }
    
    private boolean isPrime(long number) {
        if (number < 2) return false;
        for(long i = 2; i * i <= number; i++) {
            if (number % i == 0)    return false;
        }
        return true;
    }

    // 진법 변환
    private String convertBase(int number, int base) {
        if (number == 0) return "0";

        StringBuilder sb = new StringBuilder();
        while (number > 0) {
            sb.append(number % base);
            number /= base;
        }

        return sb.reverse().toString();
    }
}
```
#### 실행 결과
```
|테스트 1 〉|통과 (36.79ms, 95MB)|
|테스트 2 〉|통과 (20.12ms, 76.1MB)|
|테스트 3 〉|통과 (17.31ms, 87.1MB)|
|테스트 4 〉|통과 (16.56ms, 90.3MB)|
|테스트 5 〉|통과 (21.06ms, 75.2MB)|
|테스트 6 〉|통과 (22.76ms, 87.8MB)|
|테스트 7 〉|통과 (18.66ms, 91.2MB)|
|테스트 8 〉|통과 (19.74ms, 77.7MB)|
|테스트 9 〉|통과 (20.55ms, 78MB)|
|테스트 10 〉|통과 (16.24ms, 79.9MB)|
|테스트 11 〉|통과 (19.11ms, 83.9MB)|
|테스트 12 〉|통과 (20.33ms, 78.7MB)|
|테스트 13 〉|통과 (17.75ms, 114MB)|
|테스트 14 〉|통과 (18.45ms, 81.4MB)|
|테스트 15 〉|통과 (15.75ms, 82.2MB)|
|테스트 16 〉|통과 (19.96ms, 84.8MB)|
```
## Java Code - 소수 판별 알고리즘만 이용
```java
import java.util.*;

class Solution {
    private static final int MAX = 1_000_001;

    public int solution(int n, int k) {
        String converted = convertBase(n, k);
        String[] tokens = converted.split("0");

        int count = 0;
        for (String token : tokens) {
            if (token.isEmpty() || token.contains("0")) continue;

            long number = Long.parseLong(token);
            if (isPrime(number))        count++;
        }

        return count;
    }
    
    private boolean isPrime(long number) {
        if (number < 2) return false;
        for(long i = 2; i * i <= number; i++) {
            if (number % i == 0)    return false;
        }
        return true;
    }

    // 진법 변환
    private String convertBase(int number, int base) {
        if (number == 0) return "0";

        StringBuilder sb = new StringBuilder();
        while (number > 0) {
            sb.append(number % base);
            number /= base;
        }

        return sb.reverse().toString();
    }
}
```
#### 실행 결과
```
|테스트 1 〉|통과 (11.41ms, 73.5MB)|
|테스트 2 〉|통과 (0.09ms, 68.6MB)|
|테스트 3 〉|통과 (0.14ms, 87.6MB)|
|테스트 4 〉|통과 (0.15ms, 75.6MB)|
|테스트 5 〉|통과 (0.13ms, 81.2MB)|
|테스트 6 〉|통과 (0.13ms, 88.2MB)|
|테스트 7 〉|통과 (0.14ms, 80.5MB)|
|테스트 8 〉|통과 (0.14ms, 90.3MB)|
|테스트 9 〉|통과 (0.22ms, 87MB)|
|테스트 10 〉|통과 (0.12ms, 86.9MB)|
|테스트 11 〉|통과 (0.09ms, 78.6MB)|
|테스트 12 〉|통과 (0.15ms, 81.1MB)|
|테스트 13 〉|통과 (0.14ms, 90.5MB)|
|테스트 14 〉|통과 (0.11ms, 72.9MB)|
|테스트 15 〉|통과 (0.08ms, 72.9MB)|
|테스트 16 〉|통과 (0.09ms, 84.7MB)|
```
> 왓?  
> 실제 판별해야 할 소수 후보의 개수가 적어서 그런건가?