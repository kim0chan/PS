# 13000 ~ 13999


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
