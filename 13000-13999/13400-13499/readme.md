# 13400 ~ 13499


## 13414 : 수강신청
해시(`unordered_map`)를 이용했음.  
```cpp
for (int i = 0; i < L; i++) {
	string input;
	cin >> input;
	if (um.find(input) != um.end()) {
		um.erase(input);		
	}
	um[input] = i;
}
```
1. 원소가 이미 있는지 판단하는 부분의 코드를 잘 보십시다(`iterator`를 반환하니까!)  
2. `sort` 시에 비교 함수 정의해서 넣어주는 것도 헷갈리지 말고  
3. `unordered_map<string, int> um;`을 `vector<pair<string, int>> ans(um.begin(), um.end());`로 가져오는 것도 잘 보기
4. 벡터 `size()`함수를 `int`로 형변환하는 것도 잊어버리지 X

## 13418 : 학교 탐방하기
MST 문제로, 프림 알고리즘을 이용하여 풀었다.  
문제 자체를 잘못 이해했고, `chk`조차 관리하지 않아서 오류가 발생했는데  
디버깅에 애를 많이 썼다. 12번 제출했다 ..
