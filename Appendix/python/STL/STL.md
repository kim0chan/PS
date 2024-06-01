# 파이썬의 표준 라이브러리
* 내장함수
  * `print()`, `input()`, `sorted()` 등 기본 입·출력, 정렬 등
  * `itertools`
    * 반복되는 형태의 데이터 처리
    * 순열 조합 등 기능 제공
  * `heapq`
    * Heap을 제공하는 library
    * 우선순위 큐 사용 가능
  * `bisect`
    * Binary search 지원하는 library
  * `collections`
    * `Deque`, `Counter` 등 유용한 자료 구조를 제공하는 library
  * `math`
    * 수학적 기능 제공
    * Factorial, Root, GCD, trigonometric function 등

## 내장 함수
* 별도의 `import` 없이 사용 가능
```py
# sum(): iterable 객체가 입력으로 들어올 때 원소의 합을 반환
summation = sum([1, 2, 3])  # summation = 6

# min(), mix(): param 2개 이상 들어왔을 때 최소/최대 값을 반환
minimi = min([2, 3, 1])  # minimi = 1
maximi = max([2, 3, 1])  # maximi = 3

# eval(): 수학 수식이 문자열로 들어오면 계산 결과 값 반환
result = eval("(2 + 1) * 3")  # result = 9

# sorted(): iterable 객체의 정렬된 결과를 반환
# `key` 속성으로 정렬 기준 명시 가능 (명시하지 않으면 첫 원소 기준)
# `reverse` 속성으로 정렬 결과를 뒤집을 수 있음
sorted_list = sorted([3, 5, 4, 1, 2])  # sorted_list = [1, 2, 3, 4, 5]
sorted_list_r = sorted([3, 5, 4, 1, 2], reverse=True)  # [5, 4, 3, 2, 1]
sorted_by_key = sorted([('꼬리', 1), ('호박', 3), ('흑돌', 2)], key=lambda x : x[1])

# sort(): iterable 객체가 내장하고 있음
# 그냥 본인이 정렬됨.
a_list = [3, 2, 1, 5, 4]
a_list.sort()
print(a_list)
```

## `itertools`
* 반복되는 데이터 처리  
* `permutations`, `combinations` 등이 PS에서 유용하게 사용됨
```py
from itertools import permutations
from itertools import combinations
from itertools import product
from itertools import combinations_with_replacement
```

## `heapq`
* 최소 힙(Min Heap)으로 구성됨  
* 원소를 넣었다 빼기만 해도 $O(N \lg N)$의 오름차순 정렬 가능
* `heapq.heappush(iterable, value)`, `heapq.heappop(iterable)`
```py
import heapq

def heap_sort(iterable):
  heap = []
  result = []

  for value in iterable:
    heapq.heappush(h, value)

  for i in range(len(heap)):
    result.append(heapq.heappop(h))

  return result
```
* 최대 힙을 사용할 때는 부호를 변경하자
  * `heappush`/`heappop`할 때 (-)

## `collections`
* `deque`와 `Counter`가 유용하게 쓰임
  * `deque`에선 인덱싱, 슬라이싱 사용 불가
```py
from collections import deque

data = deque([2, 3, 4])
data.appendleft(1)
data.append(5)

listed = list(data)  # list로 변환
```
```py
from collections import Counter

counter = Counter([1, 1, 1, 2, 3, 2])
print(counter[1])  # 1 등장 횟수
print(counter[2])  # 2 등장 횟수
counter_to_dict = dict(counter)  # dict로 변환
```

## `math`
* 수학적인 기능을 제공하는 라이브러리
```py
import math

math.factorial(5)
math.sqrt(4)
math.gcd(28, 21)
math.pi
math.e
```

