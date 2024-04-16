# Python 딕셔너리 노트

## 딕셔너리 생성
```py
my_dict = {'name': 'Alice', 'age': 25}
```

## 키-값 쌍 추가(수정)
```py
# 새 키-값 쌍 추가(수정)
my_dict['city'] = 'Seoul'
```

## Key에 대한 값 반환
* 해당 property가 없을 때 default 값(두 번째 인자)을 받게 할 수 있다.
```py
value = my_dict.get('name', 'unknown')
```

## 업데이트
* 다른 딕셔너리 키-값 쌍으로 현재 딕셔너리 업데이트
```py
my_dict.update({'age': 26, 'city': 'Busan'})
```

## Key 반환
```py
keys = my_dict.keys()
```

## Value 반환
```py
values = my_dict.values()
```

## Key, Value 튜플 반환
* loop에서 딕셔너리 반복할 때 유용
```py
items = my_dict.items()
for K, V in items:
    print(f'{K}: {V}')
```

## 모든 키-값 쌍 삭제
```
my_dict.clear()
```