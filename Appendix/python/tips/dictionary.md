# Python Dictionary

### 딕셔너리 쌍 추가 / 삭제
```py
dictionary = {1: 'a'}
a[2] = 'b'
print(a)    # {1: 'a', 2: 'b'}
```

### 딕셔너리 요소 삭제
```py
dictionary = {'name': 'kim', 'age': 16, 'location': 'Seoul'}
del dictionary['name']
print(dictionary)   # {'age': 16, 'location': 'Seoul'}
```

### 딕셔너리에서 Key를 이용해 Value 얻기
```py
dictionary = {'dog': 'woo woo', 'cat': 'meow'}
print(dictionary['dog'])    # 'woo woo'
```
* 딕셔너리에서 key는 고유하기 때문에 중복되는 key 값을 설정해 놓으면 하나를 제외한 나머지 것들이 모두 무시된다.
* key로는 immutable한 값만 사용할 수 있다. (list는 사용할 수 없다.)

## 딕셔너리 관련 함수
### `keys`
```py
dictionary = {'name': 'kim', 'age': 16, 'location': 'Seoul'}
dictionary.keys()   # dict_keys(['name', 'age', 'location'])
```
* 딕셔너리의 key만을 모아 `dict_keys` 객체를 리턴한다.
    * 기본적인 반복 구문을 이용할 수 있다.
    * `list(dictionary.keys())` 이렇게 하면 리스트를 얻을 수 있다.

### `values`
```py
dictionary.values() # dict_values(['kim', 16, 'Seoul'])
```
* 딕셔너리의 value만을 모아 `dict_values` 객체를 리턴한다.

### `items`
```py
dictionary.items()  # dict_items([('name', 'kim'), ('age', 16), ('location', 'Seoul')])
```
* key와 value를 tuple로 묶은 `dict_items` 객체를 리턴한다.

### `clear`
```py
dictionary.clear()
print(dictionary)   # {}
```
* 딕셔너리 안의 모든 요소 삭제

### `get`
```py
dictionary = {'name': 'kim', 'age': 16, 'location': 'Seoul'}
dictionary.get('name')  # 'kim'
```
* key로 value를 얻는다.
    * `[]`를 이용했을 때 존재하지 않는 key를 사용하면 오류가 발생하지만
    * `get`을 사용하면 `None`을 받게된다.
        * `get(elem, 'DEFAULT_VALUE')` 이렇게 인자로 Default 값을 설정할 수 있다.

### `in`
```py
```

