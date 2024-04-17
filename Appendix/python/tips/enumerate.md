# 내장 함수 enumerate
`enumerate()`

## `for` loop
파이썬에서 `for`문을 이용하는 기본적인 방법은 `for <elem> in <list>`이다.
```py
students = ['kim', 'lee', 'park']

for student in students:
    print(student)
```
원소와 인덱스를 함께 출력하고 싶을 때는 코드를 이렇게 짤 수 있겠다.
```py
students = ['kim', 'lee', 'park']

idx = 0
for student in students:
    print(idx, letter)
    idx += 1
```
다만 이렇게 하면 `idx` 변수가 네임스페이스에 남게 된다.

내장 함수인 `range()`와 `len()`를 이용하여 루프를 돌리는 방법도 생각해볼 수 있다.
```py
students = ['kim', 'lee', 'park']

for idx in range(len(students)):
    student = students[idx]
    print(idx, student)
```
그러나 이것은 Pythonic하다고 여겨지지 않는다.

## `enumerate()`
```py
students = ['kim', 'lee', 'park']

for entry in enumerate(students):
    print(entry)

'''
(0, 'kim')
(1, 'lee')
(2, 'park')
'''
```
`enumerate()` 함수는 인덱스와 원소로 이루어진 튜플을 생성한다.

인덱스와 원소를 unpacking하여 할당할 수도 있다.
```py
students = ['kim', 'lee', 'park']

for idx, student in enumerate(students):
    print(idx, student)
```
시작 인덱스를 바꿀 수도 있다.
```py
for i, name in enumerate(some_list, start=1):
    # do something
```

## 부록
### 'Pythonic'하다는 것은 무엇일까?  
* 파이썬의 철학과 설계 원칙을 잘 따르는 코드
    * 명료함과 단순함
    * 파이썬 내장 기능, 라이브러리의 활용
    * *The Zen of Python* (PEP 20)
### 'Pythonic'하지 않은 것은 무엇인지?
* Java 혹은 C++ 스타일의 접근
* 과도한 클래스와 객체 사용
* 내장 함수 무시
### 예시
* Pythonic 하지 않은 코드
    ```py
    numbers = [1, 2, 3, 4, 5]
    doubled_numbers = []
    for i in range(len(numbers)):
        doubled_numbers.append(numbers[i] * 2)
    ```
* Pythonic 한 코드
    ```py
    numbers = [1, 2, 3, 4, 5]
    doubled_numbers = [x * 2 for x in numbers]
    ```
    * list comprehension 사용