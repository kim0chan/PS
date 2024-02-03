# C++ String
```cpp
#include <string>
```

## 비교 연산자 (`==`, `!=`)
string 간에 비교 연산자 작동함. 근데 정확히는 모르고 문자열 비교 함수 등 라이브러리가 잘 되어있으니 찾아서 읽게 되면 업데이트 ㄱㄱ

('23. 9. 2. 추가)  
C++의 `std::string` 클래스는 `==` 연산자를 이미 오버로딩하여 문자열 비교를 가능하게 만들어 놓았습니다.  
이것은 C++의 강력한 객체 지향 기능 중 하나인 연산자 오버로딩(Operator Overloading)을 활용합니다.  
`std::string` 클래스는 이미 `==` 연산자를 문자열 비교에 대한 목적으로 잘 정의하고 있으므로, 사용자는 이 연산자를 편리하게 사용​

## 대소 비교 연산자 (`<`, `>`, `<=`, `>=`)
대소 비교 연산자는 `std::string` 클래스에 직접 지원이 되지 않는다.  
std::string 클래스는 문자열의 사전식 순서를 비교할 수 있도록 `compare()` 함수를 제공한다.
```cpp
string str1 = "apple";
string str2 = "banana";
​
int result = str1.compare(str2);
if(result < 0) {
    // str1이 str2보다 사전식으로 작다.
} else if (result > 0) {
    // str1이 str2보다 사전식으로 크다.
} else {
    // str1과 str2가 사전식으로 같다.
}
```
💥 `str1 - str2` 식으로 외우면 좋지 않을까 싶다.

## `begin()`과 `end()`
`string`도 `vector`처럼 `st.begin()`이랑 `st.end()` 쓸 수 있음  
이를 이용해서 `reverse(st.begin(), st.end())`를 통해 문자열을 뒤집을 수도 있음

## 부분 문자열 함수 (`substr()` 함수)
```cpp
string st;
string temp = st.substr(0);
```
이러면 `temp`는 `[0]`부터 끝까지의 부분문자열이 된다.

('23. 9. 12.) 인자 2개도 가능?  
일단 `str.substr(pos, count)` 하면 `pos`에서 `count`개 문자 만큼인 것 같은데.. 나중에 확인 바람 [C++ 레퍼런스 - string 의 substr 함수](https://modoocode.com/235)

## 부분 문자열 찾기 (`find()` 함수)
Substring 찾기  
`문자열.find(찾을문자열, 시작인덱스, 끝인덱스)`​  
\> vector의 find랑 다르다는 것을 알아두기. ( `find(v.begin(), v.end(), target)` )

* 문자열: 찾을 대상이 되는 문자열이야.
* 찾을문자열: 찾고자 하는 문자 또는 부분 문자열이야.
* 시작인덱스: 검색을 시작할 인덱스로, 생략하면 0으로 간주되고 전체 문자열에서 검색이 시작돼.
* 끝인덱스: 검색을 종료할 인덱스로, 생략하면 전체 문자열의 끝으로 간주돼.
`find()` 함수는 찾을 문자열이 처음으로 나오는 위치를 반환해주고, 찾을 문자열이 없을 경우 -1을 반환해.​​

## 사전순 정렬 (`sort()` 함수)
string 벡터 정렬도 됨.(사전순)  
정렬할 때 길이 기준은 잘 모르겠다?

* 비교 함수 작성 시 유의할 점
```cpp
bool compare(string& a, string& b) {
    return a.length() < b.length();
}
// 💥비교 함수의 인자로 STL 혹은 클래스 객체를 전달 시에 reference를 사용한다.​​
```

## 공백이 포함된 문자열 받기 (`getline()` 함수)
```cpp
string s;
getline(cin, s);
```
이렇게 갑시다.

## 문자열(`string`)에서 정수형(`int`, `long long`)으로 바꾸는 함수
* `stoi(string st)`
* `stoll(string st)`

중간에 숫자가 아닌 문자가 있을 경우 그 전까지 나온 substring을 숫자로 변환한다.​

## 정수형(`int`)에서 문자열로 바꾸는 함수
```cpp
std::to_string(a);
```

## 문자가 숫자인지 판별 (`isdigit()` 함수)
```cpp
string a = "blahblahblah";
if (isdigit(a[0])) {
   a[0] - '0';    // <- 이 아이는 숫자가 됩니다.
}
```

## 대/소문자로 변경하는 함수
```cpp
toupper(char);
tolower(char);
```

## 숫자처럼 사용하기
```cpp
if (temp.empty())   continue;
while (temp.size() > 1 && temp[0] == '0') {
    temp.erase(0, 1);
}
ans.push_back(temp);
temp = "";​
```

## 일반 상식
```cpp
string ans;  // 빈 string 생성. ""과 같음
ans += 'a';  // 문자를 추가할 수 있음.
```
💥 여기서 주의해야 할 것은
```cpp
ans = ans + 'a';
```
이렇게 짜게 된다면 새 객체를 만들고 그걸 `ans`에 대입하게 되기 때문에 $O(N^2)$에 동작하게 된다는 점이다.  
`+=` 연산자를 이용하면 시간복잡도가 더해지는 길이에만 영향을 받는다.

## 멤버 함수
```cpp
string s = "hello";
s += " WUMONGA!";  // "hello WUMONGA!"
cout << s.size() << '\n';  // 14
cout << s.substr(2, 3) << '\n';  // "llo".  범위 넘어가면 그냥 끝까지만 출력하는 듯 싶음 .. 인자로 하나(위치) 준 거랑 똑같이
cout << s[1] << '\n'  // "e"
s.replace(6, 4, "guys")  // "hello guys"  6번 인덱스에 있는 문자(포함)부터 4자를 해당 문자열로 교체함
int it = s.find("guys");  // 6.  처음으로 나오는 인덱스
s.replace(it, 4, "everyone");  // "hello everyone"​
s.erase(7, 6);  // "hello ee".  7번 인덱스에 있는 문자(포함)부터 6자를 삭제해버림
s[6] = 'm';  // "hello me"
s.insert(0, "say ");  // "say hello me"
if(s.find("to") == string::npos)  // string::npos == -1       💥 💥 💥 find에서 존재하지 않을 경우 string::npos를 반환하는데 사실 -1과 같기 때문에 -1과 비교를 해도 상관 없다.
  cout << "'to' is not in string 's'\n";
s.empty();    // size()가 0인지
```

