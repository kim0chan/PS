# 26000 ~ 26099


## 26009 : 험난한 등굣길
BFS 문제인데 삽질을 좀 했다. 사실 아직도 잘 모르겠다.  
우선 정체 구역을 만들 때 내부까지 다 처리를 하면 TLE가 뜬다.  
그래서 테두리만 `makeObstacle` 해 주면 된다.  
그런데 바운더리를 잘 설정해서 문제가 없을 것 같은데 문제가 발생한다.  
머릿속으로 시뮬레이션을 돌려도 obstacle 생성 가능 범위랑 BFS 도는 범위랑 바운더리가 똑같아서  
문제가 없을 거라고 생각하는데  
뭐 아무튼 `makeObstacle`에 바운더리를 다음과 같이 설정했더니 정답은 떴다.

이거 적다가 생각났는데 그냥 범위를 이렇게 하면 된다.  
```cpp
void makeObstacle(int R, int C, int jhD) {
	visited[R][C] = true;
	for (int j = 0; j < D; j++) {
		if (!(R + D - j < 1 || R + D - j > N || C + j < 1 || C + j > M))		visited[R + D - j][C + j] = true;
		if (!(C + D - j < 1 || C + D - j > M || R - j < 1 || R - j > N))		visited[R - j][C + D - j] = true;
		if (!(R - (D - j) < 1 || R - (D - j) > N || C - j < 1 || C - j > M))	visited[R - (D - j)][C - j] = true;
		if (!(C - (D - j) < 1 || C - (D - j) > M || R + j < 1 || R + j > N))	visited[R + j][C - (D - j)] = true;
	}
}
```
나는바보야
