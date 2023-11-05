# 4100 ~ 4199


## 4195 : 친구 네트워크
분리집합 첫 번째 문제  
```cpp
void Union(int x, int y) {
	//cout << "Union(" << x << ", " << y << ") 호출\n";
	x = Find(x);
	y = Find(y);

	if (x < y) {
        // y를 x에 연결 ... x가 root인 그룹의 친구수 증가
		parent[y] = x;
		num_friends[x] += num_friends[y];
	}
	else if (x > y){
        // x를 y에 연결 ... y가 root인 그룹의 친구수 증가
		parent[x] = y;
		num_friends[y] += num_friends[x];
	}
}
```
대소 관계는 왜 넣어야 하는가?  
그건 잘 모르겠다. 한 bracket을 없애고 그냥 `if` 조건을 `x != y`를 넣어도 동작한다. 실행 시간은 12ms 늘어나지만..  
path compression과도 상관은 없어보인다.

