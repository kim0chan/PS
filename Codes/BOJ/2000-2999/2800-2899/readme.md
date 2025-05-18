# 2800 ~ 2899


## 2805 : 나무 자르기
parametric search를 이용하여 풀었습니다.

## 2822 : 점수 계산
간단한 구현 문제. `priority_queue`를 이용하여 `pair<int, int>`를 정렬하였음

## 2839 : 설탕 배달

## 2841 : 외계인의 기타 연주

## 2847 : 게임을 만든 동준이
그리디 구현 문제

## 2846 : 오르막길
그냥 구현 문제이다.

## 2870 : 수학숙제
답을 저장할 때 `int`나 `unsigned long long` 등 해도 터진다.  
문자열로 저장하고 정렬해서 출력하면 정답이다.  
문자열로 저장할 때 `002` 같은 숫자를 주의해야 한다.  
```cpp
if (temp.empty())	continue;
while (temp.size() > 1 && temp[0] == '0') {
    temp.erase(0, 1);
}
ans.push_back(temp);
temp = "";
```
이렇게 해서 맨 앞의 `0`들을 trim하는데, 숫자 0은 그대로 내버려 둬야 하기 때문에 `temp.size() > 1`일 때 `temp.erase(0, 1)`을 반복해서 수행한다.
