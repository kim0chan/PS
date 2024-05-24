# Python Class
코테엔 필요 없다.  
그러나 COS Pro 등의 시험에선 클래스 관련 코드 작성하는 문제가 출제되기도 한다. 👻

```py
class Person:
    # 생성자
    def __init__(self):
        self.age = 0
    
    def introduce(self):
        return f'hi i am {self.age} years old'

lee = Person()
print(lee.introduce())  # 'hi i am 0 years old'
```



