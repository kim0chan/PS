# Python String
파이썬 문자열

## Slicing

## Formatting

## String Operations

## Useful Functions
유용한 함수들
### `count`
```py
a = 'grammy'
a.count('m')    # 2
a.count('am')   # 1
```
문자열에 인자로 들어간 문자열의 개수를 리턴함

### `find`
```py
a = 'grammy'
a.find('a')     # 2
```
문자열에 인자로 들어간 문자열이 처음으로 나온 위치를 반환  
찾으려는 substring이 존재하지 않으면 `-1`을 반환

### `index`
`find`랑 비슷한데 문자열을 못 찾으면 오류가 발생함
```
ValueError: substring not found
```

### `join`
```py
'-'.join('kim')     # 'k-i-m`
```
인자 문자열의 각 문자 사이에 문자열을 삽입  
```py
'-'.join(['k', 'i', 'm'])   # 'k-i-m`
```
리스트나 튜플도 입력으로 사용 가능

### `upper`
```py
a = 'hello'
a.upper()   # 'HELLO'
```
소문자를 대문자로 바꾼 값을 리턴  

### `lower`
```py
a = 'HELLO'
a.lower()   # 'hello'
```
대문자를 소문자로 바꾼 값을 리턴  

### `strip`
```py
a = '  hello   '
a.strip()   # 'hello'
```
문자열 양쪽에 있는 연속된 공백을 모두 지운 값을 리턴  
* `lstrip`
    * 문자열 왼쪽의 연속된 공백을 모두 지움
* `rstrip`
    * 문자열 오른쪽의 연속된 공백을 모두 지움

### `replace`
```py
a = 'Drake wins'
a.replace('Drake', 'Kendrick')  # 'Kendrick wins'
```
`replace(바뀔문자열, 바꿀문자열)` 형식으로 문자열 안의 substring을 다른 substring으로 치환한 값을 반환함

### `split`
```py
a = 'king of the dot'
a.split()   # ['king', 'of', 'the', 'dot']
```
인자로 들어온 substring을 구분자(delimiter)로 문자열을 나눠줌  
인자가 없으면 공백(`\t`, `\r`, `\n`)을 기준으로 나눠버림

> ### Immutable
> 문자열은 자체 값을 변경할 수 없는 immutable 자료형이다.  
> 문자열 내장 함수를 수행해도 보통 결과값이 return된다.  
> 원본 값은 변경되지 않으므로 변경하고 싶다면 함수 실행 결과를 대입하면 된다.
